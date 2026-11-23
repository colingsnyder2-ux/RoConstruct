// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is the inlined std::set<int>::_Buynode(): allocate one node
// through the node allocator at this+0xC, then construct the _Left, _Parent
// and _Right pointer fields through the pointer allocator at this+0x10.
// The disassembly stops at the jmp to 0x54539f, so everything after the third
// construct (the return path and any catch cleanup) is guessed.

extern "C" int fn_0054c630(int a1);
extern "C" char *fn_0054c640(char* self);
extern "C" char *fn_00541da0(char* self);

// allocator<_Node>::allocate(count), this = node allocator at this+0xC
extern "C" int __fastcall fn_00545b50(void* alloc, int unusedEdx, int count);
// allocator<_Node*>::construct(ptr, value), this = pointer allocator at this+0x10
extern "C" void __fastcall fn_00550e30(void* alloc, int unusedEdx, int ptr, int* value);

extern "C" int __fastcall fn_00545260(void* self, int unusedEdx)
{
    char* base = (char*)self;
    int node = fn_00545b50(base + 0xc, 0, 1);
    int constructed = 0;
    try {
        int v0 = 0;
        fn_00550e30(base + 0x10, 0, fn_0054c630(node), &v0);
        ++constructed;

        int v1 = 0;
        // INFERRED: the original passes the node as both ecx and the stack argument
        fn_00550e30(base + 0x10, 0, fn_0054c640((void*)node, 0, node), &v1);
        ++constructed;

        int v2 = 0;
        fn_00550e30(base + 0x10, 0, fn_00541da0((void*)node, 0, node), &v2);
    } catch (...) {
        throw;
    }
    return node;
}
