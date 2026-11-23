// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: callee names are mislabeled analogs; real types unknown. Treat as
// "ctor(self, other): self->field0 = 0; self->setPointer(other->count())".
struct Obj545e30 {
    int field0;
};

extern "C" int __fastcall fn_00540e80(void* self, int unusedEdx);
extern "C" void __fastcall fn_00598fa0(Obj545e30* self, int unusedEdx, int value);

extern "C" Obj545e30* __fastcall fn_00545e30(Obj545e30* self, int unusedEdx, void* arg1)
{
    self->field0 = 0;
    fn_00598fa0(self, 0, fn_00540e80(arg1, 0));
    return self;
}
