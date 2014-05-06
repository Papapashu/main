#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
const int kmax=20,mmax=20;
using namespace std;

void transform(int mask[][mmax], char vis[][mmax],int c,int i,int l) //Изменяет числовую матрицу в зависимости от условий
{
    if(i>0 && l>0)mask[i-1][l-1]+=c;
    if(l>0)mask[i][l-1]+=c;
    if(l>0 && i<kmax-1)mask[i+1][l-1]+=c;
    if(i<kmax-1)mask[i+1][l]+=c;
    if(l<mmax-1 && i<kmax-1)mask[i+1][l+1]+=c;
    if(i<kmax-1)mask[i][l+1]+=c;
    if(i>0 && i<kmax-1)mask[i-1][l+1]+=c;
    if(i>0)mask[i-1][l]+=c;
}

void viv(int mask[][mmax], char vis[][mmax]) //Типо вывод
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

int main()
{
  int mask[kmax][mmax];
  char vis[kmax][mmax];
  int ngen;

   cout<<"Введите количество поколений(шагов):";
   cin >> ngen;
   cout << endl;

   for(int i=0; i<kmax;i++)
       for(int l=0; l<mmax;l++)
       {
           mask[i][l]=0;
       }
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
               transform(mask,vis,1,i,l);
           }
       }
   
   viv(mask,vis);
   for(int p=0;p<ngen;p++){
       for(int i=0; i<kmax;i++){
           for(int l=0; l<mmax;l++)
           {
               if(mask[i][l]==3 && vis[i][l]=='_')
               {
                   vis[i][l]='*';
                   transform(mask,vis,1,i,l);
               }
               else if(mask[i][l]>3 && vis[i][l]=='*')
                  {
                   vis[i][l]='_';
                   transform(mask,vis,-1,i,l);
               }
               else if(mask[i][l]<2 && vis[i][l]=='*')
               {
                   vis[i][l]='_';
                   transform(mask,vis,-1,i,l);

               }
           }
       }
       viv(mask,vis);
    }
   return 0;
}
