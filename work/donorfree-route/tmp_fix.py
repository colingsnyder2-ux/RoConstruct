p="C:/Users/colin/RoConstruct/rebuild/2008-06/native-classes/AutoRecover_0054e6b0.cpp"
s=open(p).read()
s=s.replace("unsigned int __fastcall fn_0054f980(Local_0054e6b0* self, int unusedEdx);","unsigned int __fastcall fn_0054f980(Local_0054e6b0* self);")
s=s.replace("void** __fastcall fn_005423f0(Local_0054e6b0* self, int unusedEdx);","void** __fastcall fn_005423f0(Local_0054e6b0* self);")
s=s.replace("void** __fastcall fn_005508e0(Local_0054e6b0* self, int unusedEdx);","void** __fastcall fn_005508e0(Local_0054e6b0* self);")
s=s.replace("void** __fastcall fn_0054cec0(Local_0054e6b0* self, int unusedEdx);","void** __fastcall fn_0054cec0(Local_0054e6b0* self);")
for fn in ["fn_0054f980","fn_005423f0","fn_005508e0","fn_0054cec0"]:
    s=s.replace(fn+"(this, 0)",fn+"(this)")
open(p,"w").write(s)
print("done")