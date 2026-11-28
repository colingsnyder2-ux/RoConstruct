p="C:/Users/colin/RoConstruct/rebuild/2008-06/native-classes/AutoRecover_0054e6b0.cpp"
s=open(p).read()
marker="void* Local_0054e6b0::_Insert(void* result"
idx=s.index(marker)
head=s[:idx]
tail=s[idx:]
tail=tail.replace("self","this")
open(p,"w").write(head+tail)
print("done")
