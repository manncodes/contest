import pandas as pd

df = pd.read_csv('d:\temp.csv')


# get the top rows with maxiumum value of column 'A'

df.nlargest(3, 'A')