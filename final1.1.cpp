#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
const int kmax=20,mmax=20;
using namespace std;

void transform(int **maskcl, char **vis,int c,int i,int l)
{
    if(i>0 && l>0)maskcl[i-1][l-1]+=c;
    if(l>0)maskcl[i][l-1]+=c;
    if(l>0 && i<kmax-1)maskcl[i+1][l-1]+=c;
    if(i<kmax-1)maskcl[i+1][l]+=c;
    if(l<mmax-1 && i<kmax-1)maskcl[i+1][l+1]+=c;
    if(i<kmax-1)maskcl[i][l+1]+=c;
    if(i>0 && i<kmax-1)maskcl[i-1][l+1]+=c;
    if(i>0)maskcl[i-1][l]+=c;
}

void viv(int **mask, char **vis)
{
    for(int i=0; i<kmax;i++)
     {
        for(int l=0; l<mmax;l++)
        {
           cout<< mask[i][l];
        }
        cout << endl;
    }
     cout<<endl;

    for(int i=0; i<kmax;i++)
     {
        for(int l=0; l<mmax;l++)
        {
           printf("%c",vis[i][l]);
        }
        cout << endl;
    }
  cout<<endl;
  cout<<endl;
}

void lifemain(char **vis,int ngen,int mmax,int kmax)
{
    int **mask = new int *[kmax];
          for (int i=0; i<mmax; i++)
             mask[i] = new int [mmax];

          int **maskcl = new int *[kmax];
                for (int i=0; i<mmax; i++)
                   maskcl[i] = new int [mmax];


 for(int i=0; i<kmax;i++)
     for(int l=0; l<mmax;l++)
     {
         mask[i][l]=0;
     }
 for(int i=0; i<kmax;i++)
     for(int l=0; l<mmax;l++)
     {
         if(vis[i][l]=='*')
         {
             transform(mask,vis,1,i,l);
         }
     }


 for(int i=0; i<kmax;i++)
     for(int l=0; l<mmax;l++)
     {
         maskcl[i][l]=mask[i][l];
     }
  viv(maskcl,vis);

 for(int p=0;p<ngen;p++){
     for(int i=0; i<kmax;i++){
         for(int l=0; l<mmax;l++)
         {
             if(mask[i][l]==3 && vis[i][l]=='_')
             {
                 vis[i][l]='*';
                 transform(maskcl,vis,1,i,l);
             }
             else if(mask[i][l]>3 && vis[i][l]=='*')
                {
                 vis[i][l]='_';
                 transform(maskcl,vis,-1,i,l);
             }
             else if(mask[i][l]<2 && vis[i][l]=='*')
             {
                 vis[i][l]='_';
                 transform(maskcl,vis,-1,i,l);

             }
         }
     }


     for(int i=0; i<kmax;i++)
         for(int l=0; l<mmax;l++)
         {
             mask[i][l]=maskcl[i][l];
         }

     viv(mask,vis);
  }
}


int main()
{
    //char vis[kmax][mmax];

    char **vis = new char *[kmax];
          for (int i=0; i<mmax; i++)
             vis[i] = new char [mmax];

    int ngen;

    cout<<"Āāåäčņå źīėč÷åńņāī ļīźīėåķčé(ųąćīā):";
    cin >> ngen;
    cout << endl;

    for(int i=0; i<kmax;i++)
        for(int l=0; l<mmax;l++)
        {
            if((rand() + i*l)%2 == 1)
            {
                vis[i][l]='_';
            }
            else
            {
                vis[i][l]='*';
            }
        }
    lifemain(vis,ngen,mmax,kmax);
}
