// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 00442db0  unit: CPropGrid  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00442db0
//
// 00442db0  8b5104               mov edx, dword ptr [ecx + 4]
// 00442db3  33c0                 xor eax, eax
// 00442db5  c701c0578100         mov dword ptr [ecx], 0x8157c0
// 00442dbb  3bd0                 cmp edx, eax
// 00442dbd  7426                 je 0x442de5
// 00442dbf  52                   push edx
// 00442dc0  894104               mov dword ptr [ecx + 4], eax
// 00442dc3  894108               mov dword ptr [ecx + 8], eax
// 00442dc6  89410c               mov dword ptr [ecx + 0xc], eax
// 00442dc9  894110               mov dword ptr [ecx + 0x10], eax
// 00442dcc  894118               mov dword ptr [ecx + 0x18], eax
// 00442dcf  894114               mov dword ptr [ecx + 0x14], eax
// 00442dd2  c74120ffffffff       mov dword ptr [ecx + 0x20], 0xffffffff
// 00442dd9  88411d               mov byte ptr [ecx + 0x1d], al
// 00442ddc  88411c               mov byte ptr [ecx + 0x1c], al
// 00442ddf  ff1550218000         call dword ptr [0x802150]
// 00442de5  c3                   ret 

struct CPropGrid
{
    void* vtable;
    void* field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    char field1C;
    char field1D;
    int field20;
    void destroy();
};

extern "C" int (__stdcall *DeleteObject)(void*);

void CPropGrid::destroy()
{
    void* p = field4;
    vtable = (void*)0x8157c0;
    if (p != 0)
    {
        field4 = 0;
        field8 = 0;
        fieldC = 0;
        field10 = 0;
        field18 = 0;
        field14 = 0;
        field20 = -1;
        field1D = 0;
        field1C = 0;
        DeleteObject(p);
    }
}
