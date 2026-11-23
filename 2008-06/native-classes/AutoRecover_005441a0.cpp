// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

// INFERRED: object layout unknown; allocator lives at self+0xc (ecx+0xc passed to allocate).
extern "C" int __fastcall fn_00550e10(void* alloc, int unusedEdx, int count);
extern "C" int __fastcall fn_00545a10(void* self, int unusedEdx, int a1, int a2, int a3, int a4, int a5);

// INFERRED: target is unnamed; the disassembly shows 5 stack args read from [ebp+8..0x18] (last one a byte).
extern "C" void* __fastcall fn_005441a0(char* self, int unusedEdx, int a1, int a2, int a3, int a4, unsigned char a5)
{
    void* where = (void*)fn_00550e10(self + 0xc, 0, 1);
    void* mem = ::operator new(0x18, where);
    void* node = 0;
    if (mem)
        node = (void*)fn_00545a10(mem, 0, a1, a2, a3, a4, a5);
    return node;
}
