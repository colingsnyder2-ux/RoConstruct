p="C:/Users/colin/RoConstruct/rebuild/2008-06/native-classes/AutoRecover_0054b520.cpp"
s=open(p).read()
s=s.replace("fn_0054cd10(self, 0, _Fixnodeparent)","((int(__thiscall*)(void*,NodePtr))fn_0054cd10)(self, _Fixnodeparent)")
s=s.replace("fn_0054cd10(self, 0, _Pnode)","((int(__thiscall*)(void*,NodePtr))fn_0054cd10)(self, _Pnode)")
s=s.replace("fn_0054cee0(self, 0, _Pnode)","((int(__thiscall*)(void*,NodePtr))fn_0054cee0)(self, _Pnode)")
s=s.replace("fn_0054cee0(self, 0, _Fixnodeparent)","((int(__thiscall*)(void*,NodePtr))fn_0054cee0)(self, _Fixnodeparent)")
s=s.replace("fn_00544730(self, 0, ret, whereCont, wherePtr)","((TreeIter*(__thiscall*)(void*,TreeIter*,int,void*))fn_00544730)(self, ret, whereCont, wherePtr)")
open(p,"w").write(s)
print("done")