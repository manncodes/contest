for l in [*open(0)][2::2]:
 c,a=0,(l+'1 2').split()
 while a[c]=='1':c+=1
 print('SFeicrosntd'[c+1&1::2])