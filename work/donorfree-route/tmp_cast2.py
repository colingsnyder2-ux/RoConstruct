import re
p="C:/Users/colin/RoConstruct/rebuild/2008-06/native-classes/AutoRecover_0054f3f0.cpp"
s=open(p).read()
s=s.replace(
"void* _Newnode = fn_00550a30(this, 0, this->_Myhead, _Wherenode, this->_Myhead, _Val, 0);",
"void* _Newnode = ((void*(__thiscall*)(void*,void*,void*,void*,const void*,char))fn_00550a30)(this, this->_Myhead, _Wherenode, this->_Myhead, _Val, 0);")
s=s.replace("fn_00550900(this, 0, _Pnode)","((void(__thiscall*)(void*,void*))fn_00550900)(this, _Pnode)")
s=s.replace("fn_00544070(this, 0, _Pnode)","((void(__thiscall*)(void*,void*))fn_00544070)(this, _Pnode)")
# fn_00544070(this, 0, *fn_...) pattern
s=re.sub(r"fn_00544070\(this, 0, (\*fn_[0-9a-f]+\([^)]*\))\)", lambda m: "((void(__thiscall*)(void*,void*))fn_00544070)(this, %s)"%m.group(1), s)
s=re.sub(r"fn_00550900\(this, 0, (\*fn_[0-9a-f]+\([^)]*\))\)", lambda m: "((void(__thiscall*)(void*,void*))fn_00550900)(this, %s)"%m.group(1), s)
s=s.replace("fn_0054e320(result, 0, _Newnode, this)",
            "((void*(__thiscall*)(void*,void*,void*))fn_0054e320)(result, _Newnode, this)")
open(p,"w").write(s)
print("done")