# %%
"""
get all the AC solutions from codeforces #1783 Educational Codeforces Round 141 (Rated for Div. 2) for problem B
"""
import os, sys, re, requests, json, time
from bs4 import BeautifulSoup
import pandas as pd
from tqdm.auto import tqdm
from joblib import Parallel, delayed

# %%
def get_solution_links(page_no):
    try:
        URL = f"https://codeforces.com/contest/1783/status/page/{page_no}?order=BY_JUDGED_DESC"
        re = requests.get(URL)
        soup = BeautifulSoup(re.text, "html.parser")
        table = soup.find("table", {"class": "status-frame-datatable"})
        rows = table.find_all("tr")
        links = []
        for row in rows:
            td_data_problemid = row.find("td", {"data-problemid": "1728811"})
            if td_data_problemid is not None:
                span_verdict = row.find("span", {"submissionverdict": "OK"})
                if span_verdict is not None:
                    # find the href of a in class "view-source"
                    a = row.find("a")
                    if a.get("class") == ["view-source"]:
                        href = a.get("href")
                        # print("https://codeforces.com" + href)
                        links.append("https://codeforces.com" + href)

        print(f"page_no: {page_no}, links: {len(links)}")
        if links:
            pd.DataFrame(links).to_csv(f"data/{page_no}.csv", index=False)
        return True
    except:
        return None


# %%

if __name__ == "__main__":
    results = Parallel(n_jobs=-1)(
        delayed(get_solution_links)(page_no) for page_no in tqdm(range(431,1,-1))
    )

    