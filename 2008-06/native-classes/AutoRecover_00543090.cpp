// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: std::set<int> _Tree layout (MSVC 2008): _Myhead at +0x18, _Mysize at +0x1c.
struct TreeSetInt {
    char pad[0x18];
    void* head;
    int size;
};

// INFERRED: call site pushes no args, so Buynode helper is declared with 0 stack args.
extern "C" void* __fastcall fn_00545260(void* self, int unusedEdx);
extern "C" int fn_00542e00(int value);
extern "C" void** __fastcall fn_005423f0(void* self, int unusedEdx);
extern "C" void** __fastcall fn_005508e0(void* self, int unusedEdx);
extern "C" void** __fastcall fn_0054cec0(void* self, int unusedEdx);

extern "C" void __fastcall fn_00543090(TreeSetInt* self, int unusedEdx)
{
    self->head = fn_00545260(self, 0);
    *fn_00542e00(self, 0, self->head) = 1;
    *fn_005423f0(self, 0) = self->head;
    *fn_005508e0(self, 0) = self->head;
    *fn_0054cec0(self, 0) = self->head;
    self->size = 0;
}
