import re
p="C:/Users/colin/RoConstruct/rebuild/2008-06/native-classes/AutoRecover_0054e6b0.cpp"
s=open(p).read()
# fn_0054fb80 call
s=s.replace(
"void* _Newnode = fn_0054fb80(this, 0, this->_Myhead, _Wherenode, this->_Myhead, _Val, 0);",
"void* _Newnode = ((void*(__thiscall*)(void*,void*,void*,void*,const void*,char))fn_0054fb80)(this, this->_Myhead, _Wherenode, this->_Myhead, _Val, 0);")
# fn_0054cd10 calls: pattern fn_0054cd10(this, 0, X) -> cast
def cast_cd10(m):
    x=m.group(1)
    return "((void(__thiscall*)(void*,void*))fn_0054cd10)(this, %s)"%x
s=re.sub(r"fn_0054cd10\(this, 0, ([^)]+(?:\)[^)]*)*)\)", lambda m: "((void(__thiscall*)(void*,void*))fn_0054cd10)(this, %s)"%m.group(1), s)
# fn_0054cee0 calls
s=re.sub(r"fn_0054cee0\(this, 0, ([^)]+(?:\)[^)]*)*)\)", lambda m: "((void(__thiscall*)(void*,void*))fn_0054cee0)(this, %s)"%m.group(1), s)
# fn_0054e320 call
s=s.replace(
"fn_0054e320(result, 0, _Newnode, this)",
"((void*(__thiscall*)(void*,void*,void*))fn_0054e320)(result, _Newnode, this)")
open(p,"w").write(s)
print("done")
PY