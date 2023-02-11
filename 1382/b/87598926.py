for l in [*open(0)][2::2]:
 c=1
 for x in(l+'1 2').split():
  if x=='1':c^=1
  else:break
 print('SFeicrosntd'[c::2])