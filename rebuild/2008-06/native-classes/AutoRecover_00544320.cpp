// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

extern "C" int __fastcall fn_005425f0(void* self, int unusedEdx, int a1);

// INFERRED: object layout unknown; first dword is zeroed
struct Obj {
    int first;
};

extern "C" Obj* __fastcall fn_00544320(Obj* self, int unusedEdx, int* arg)
{
    self->first = 0;
    fn_005425f0(self, 0, *arg);
    return self;
}
