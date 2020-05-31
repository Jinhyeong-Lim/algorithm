import urllib.request
from bs4 import BeautifulSoup

url ='https://sites.google.com/site/songhyunje'
html = urllib.request.urlopen(url).read()
soup = BeautifulSoup(html, 'html.parser')
#print(soup)

title = soup.find_all(class_='zfr3Q')
print(len(title))

for i in title :
    t = soup.find_all(class_='zfr3Q')
    for j in t :
        print(j.attrs[t])
