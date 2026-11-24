// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: std::set<int> _Buyheadnode-style init; only the code up to the jmp at 0x54562a is shown.
// INFERRED: allocators sit at this+0xc (node alloc) and this+0x10 (pointer alloc).
extern "C" int __fastcall fn_00550e10(void* alloc, int unusedEdx, int count);
extern "C" void __fastcall fn_00550e30(void* alloc, int unusedEdx, int* where, int* value);
// disasm shows "add esp, 4" after each call, so these are cdecl; the inferred __thiscall convention does not match.
extern "C" int fn_0054c630(int node);
extern "C" int fn_0054c640(int node);
extern "C" int fn_00541da0(int node);

struct SetImpl {
    char pad[0xc];
    char nodeAlloc;   // +0xc
    char pad2[3];
    char ptrAlloc;    // +0x10
};

extern "C" void __fastcall fn_00545550(SetImpl* self, int unusedEdx)
{
    int node = fn_00550e10(&self->nodeAlloc, 0, 1);
    int count = 0;
    int nullPtr = 0;

    int left = fn_0054c630(node);
    fn_00550e30(&self->ptrAlloc, 0, (int*)left, &nullPtr);
    ++count;

    int nullPtr2 = 0;
    int parent = fn_0054c640(node);
    fn_00550e30(&self->ptrAlloc, 0, (int*)parent, &nullPtr2);
    ++count;

    int nullPtr3 = 0;
    int right = fn_00541da0(node);
    fn_00550e30(&self->ptrAlloc, 0, (int*)right, &nullPtr3);
}
