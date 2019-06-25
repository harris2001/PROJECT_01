import urllib
from BeautifulSoup import BeautifulSoup

a = 0

while True:
  url = 'https://eservices.moec.gov.cy/ypexams/pagkypries/ypopsifioi/2019/vathmologies'

  page = urllib.urlopen(url)
  soup = BeautifulSoup(page)
  
  table = soup.find("pre").contents[0]
  print ("+++++++++++++++_________ ",table)

  ext = soup.html.body.find('pre').text
  print (urllib.urlopen(url).read())
  print ("___________________________________")
  if "KEY" in page.read():
    print(page.read())
    break
  url = url+"&captcha="+ext
  urllib.urlopen(url)
  print (url)
  a = a+1

