# -*- coding: utf-8 -*- 
#!/usr/bin/env python3
 
import csv
import urllib3
import cssselect
import urllib3.request
from lxml.html import fromstring
import lxml
pool = urllib3.PoolManager()

BASE_URL = 'http://www.adme.ru/'
ITEM_PATH = '.content .article-list .article-list-block .al-title a'
TITLE_PATH = '.content .article h1'
TEXT_PATH = '.content .article p'

def get_html(url):
    response = pool.urlopen('POST',url)
    return response.read().decode('utf-8')
 
def parse_html(html):
    html_string = fromstring(html)
    count = 0
    for elem in html_string.cssselect(ITEM_PATH):
        article_link = str(BASE_URL[0:-1] + elem.get('href'))
        #print get_html(article_link)
        articleh_string = fromstring(get_html(article_link))
        art_title = articleh_string.cssselect(TITLE_PATH)[0].text
        art_descr = articleh_string.cssselect(TEXT_PATH)[1].text
        text_result = ''
        for text_part in articleh_string.cssselect(TEXT_PATH):
            text_result = text_result + lxml.etree.tostring(text_part, encoding='utf-8')
        if count == 0:
            print '------------------------'
            print art_title
            print '------------------------'
            print art_descr
            print '------------------------'
            print text_result
        count = count+1
 
def main():
    parse_html(get_html(BASE_URL))

if __name__ == '__main__':
    main() 
