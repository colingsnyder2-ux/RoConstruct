p="C:/Users/colin/RoConstruct/rebuild/2008-06/native-classes/AutoRecover_0054b520.cpp"
s=open(p).read()
marker="TreeIter* Local_0054b520::erase(TreeIter* ret, int whereCont, void* wherePtr)"
idx=s.index(marker)
head=s[:idx]
tail=s[idx:]
# remove the self assignment line
tail=tail.replace("    TreeObj* self = (TreeObj*)this;\n","")
# replace self -> this in body
tail=tail.replace("self","this")
s=head+tail
open(p,"w").write(s)
print("done")