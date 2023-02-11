"""
get all the AC solutions from codeforces #1783 Educational Codeforces Round 141 (Rated for Div. 2) for problem B
"""
import os, sys, re, requests, json, time
from bs4 import BeautifulSoup

PAGE_NO = 1000

URL = f"https://codeforces.com/contest/1783/status/page/{PAGE_NO}?order=BY_JUDGED_DESC"

re = requests.get(URL)
soup = BeautifulSoup(re.text, "html.parser")
table = soup.find("table", {"class": "status-frame-datatable"})

rows = table.find_all("tr", {"class": "status-frame-datatable"})

for row in rows:
    check = False
    # find if td with data-problemid="1728810"  exists
    for td in row.find_all("td"):
        if td.get("data-problemid") == "1728810":
            check = True
            break
    if check:
        # find the href of a in class "view-source"
        a = row.find("a")
        if a.get("class") == ["view-source"]:
            href = a.get("href")
            print(href)
