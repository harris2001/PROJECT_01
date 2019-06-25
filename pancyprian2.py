
from selenium.webdriver.common.keys import Keys
import urllib.request
from selenium import webdriver
from bs4 import BeautifulSoup
import time
import pandas as pd

url ='https://eservices.moec.gov.cy/ypexams/pagkypries/ypopsifioi/2019/vathmologies'

print(url)

##for i in range(1,309):

page = urllib.request.urlopen(url)
soup = BeautifulSoup(page, 'html.parser')
results = soup.find_all('td')
print(results)

    ###driver = webdriver.Firefox(executable_path = '/root/Downloads/geckodriver-v0.23.0-arm7hf')

    #response = requests.get(url)
    #soup = BeautifulSoup(response.text)
    #soup.find(id=i)
    
    #driver = webdriver.Firefox()
    #driver.get(url)
    #driver.execute_script('ASPx.GVPagerOnClick(\'ctl00_ctl00_MainPane_Content_MainContent_ASPxGrid_grid\',\'PN\'+i)')

driver = webdriver.Firefox(executable_path = 'i/root/Downloads/geckodriver-v0.23.0-arm7hf/geckodriver')
#driver = webdriver.Firefox()
driver.get(url)

###for i in range(1,309):
    ###print (i+"+++++++++++++++++++++++++++++++++++++++++\n\n\n")
    ###driver.execute_script('ASPx.GVPagerOnClick(\'ctl00_ctl00_MainPane_Content_MainContent_ASPxGrid_grid\',\'PN\'+i)');
results = driver.find_elements_by_class_name("dxgv");
webContent = response.read()
with open("out.txt","a") as myfile:
    myfile.write(result)
f = open('out.txt', 'w')
f.write(result)
f.close
