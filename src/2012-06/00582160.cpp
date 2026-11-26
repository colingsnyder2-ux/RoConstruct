// from server: 100% by Xemicl
// from server: 100% by atomic.potato
// roc 2012-06 00580920  unit: RBX::VTouchTransmitter::?$FactoryProduct::Creator  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00580920
//
// 00580920  56                   push esi
// 00580921  8b742408             mov esi, dword ptr [esp + 8]
// 00580925  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00580928  85c0                 test eax, eax
// 0058092a  7409                 je 0x580935
// 0058092c  50                   push eax
// 0058092d  e8e2174000           call 0x982114
// 00580932  83c404               add esp, 4
// 00580935  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0058093c  c7462000000000       mov dword ptr [esi + 0x20], 0
// 00580943  c7462400000000       mov dword ptr [esi + 0x24], 0
// 0058094a  5e                   pop esi
// 0058094b  c20400               ret 4

extern "C" void __cdecl ReleaseObject(void*);

struct S
{
    int pad[0x3];
    void* a;
    void* b;
    void* c;

    void __stdcall f();
};

void __stdcall S::f()
{
    if (a != 0)
        ReleaseObject(a);
    a = 0;
    b = 0;
    c = 0;
}
