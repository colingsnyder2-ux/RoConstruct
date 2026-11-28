ADDR="0054b520"
p="C:/Users/colin/RoConstruct/rebuild/2008-06/native-classes/AutoRecover_%s.cpp"%ADDR
s=open(p).read()
s=s.replace("struct TreeObj;","struct Local_%s {\n    TreeIter* erase(TreeIter* ret, int whereCont, void* wherePtr);\n};\nstruct TreeObj;"%ADDR)
old_def="extern \"C\" TreeIter* __fastcall fn_%s(TreeObj* self, int unusedEdx, TreeIter* ret, int whereCont, void* wherePtr)"%ADDR
new_def="TreeIter* Local_%s::erase(TreeIter* ret, int whereCont, void* wherePtr)"%ADDR
assert old_def in s, "def not found"
s=s.replace(old_def,new_def)
idx=s.index(new_def)
brace=s.index("{",idx)
s=s[:brace+1]+"\n    TreeObj* self = (TreeObj*)this;"+s[brace+1:]
open(p,"w").write(s)
print("done")