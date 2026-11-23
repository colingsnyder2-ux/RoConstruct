// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: fn_006a0920 is an allocator (operator new style); only the size is pushed.
extern "C" void* fn_006a0920(int size);
extern "C" void* __fastcall fn_004d7a10(void* self, int unusedEdx, int a1);

// INFERRED: the code does `new T(this + 8)`, where T is a 0x28-byte object, and returns null if allocation fails.
extern "C" void* __fastcall fn_004d7a80(char* self, int unusedEdx)
{
    void* mem = fn_006a0920(0x28);
    if (mem)
    {
        return fn_004d7a10(mem, 0, (int)(self + 8));
    }
    return 0;
}
