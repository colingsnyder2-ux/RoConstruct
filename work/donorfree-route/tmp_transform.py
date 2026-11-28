# params
ADDR="0054f3f0"
# helpers
ZERO=["fn_00543650","fn_005423f0","fn_005508e0","fn_0054cec0"]
# 1+-stack helpers to cast: (name, call signature pattern)
p="C:/Users/colin/RoConstruct/rebuild/2008-06/native-classes/AutoRecover_%s.cpp"%ADDR
s=open(p).read()
# flags
s=s.replace("// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS",
            "// native-flags: /O2 /Ob2 /Oy /GF /GS /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS")
# struct: add method
s=s.replace(
"""struct Local_%s
{
    char pad[0x18];
    void* _Myhead;
    unsigned int _Mysize;
};"""%ADDR,
"""struct Local_%s
{
    char pad[0x18];
    void* _Myhead;
    unsigned int _Mysize;
    void* _Insert(void* result, bool _Addleft, void* _Wherenode, const void* _Val);
};"""%ADDR)
# function def
s=s.replace(
"extern \"C\" void* __fastcall fn_%s(Local_%s* self, int unusedEdx, void* result,\n                                       bool _Addleft, void* _Wherenode, const void* _Val)\n{"%(ADDR,ADDR),
"void* Local_%s::_Insert(void* result, bool _Addleft, void* _Wherenode, const void* _Val)\n{"%ADDR)
# replace self->this in body (after def marker)
marker="void* Local_%s::_Insert"%ADDR
idx=s.index(marker)
head=s[:idx]; tail=s[idx:]
tail=tail.replace("self","this")
s=head+tail
# drop dummy from zero-stack helpers (declarations + calls)
for fn in ZERO:
    # declaration: fn(Local_ADDR* self, int unusedEdx) -> (self)
    s=s.replace("extern \"C\" unsigned int __fastcall %s(Local_%s* self, int unusedEdx);"%(fn,ADDR),
                "extern \"C\" unsigned int __fastcall %s(Local_%s* self);"%(fn,ADDR))
    s=s.replace("extern \"C\" void** __fastcall %s(Local_%s* self, int unusedEdx);"%(fn,ADDR),
                "extern \"C\" void** __fastcall %s(Local_%s* self);"%(fn,ADDR))
    s=s.replace("%s(this, 0)"%fn,"%s(this)"%fn)
open(p,"w").write(s)
print("basic done")
