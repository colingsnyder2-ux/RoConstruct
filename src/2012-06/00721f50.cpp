// from server: 100% by Xemicl
// from server: 100% by Intel
// roc 2012-06 00700e40  unit: RBX::VDebugSettings::?$BoundFuncDesc  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00700e40
//
// 00700e40  56                   push esi
// 00700e41  8b742408             mov esi, dword ptr [esp + 8]
// 00700e45  57                   push edi
// 00700e46  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00700e4a  3bf7                 cmp esi, edi
// 00700e4c  7410                 je 0x700e5e
// 00700e4e  8bff                 mov edi, edi
// 00700e50  8bce                 mov ecx, esi
// 00700e52  e819eaffff           call 0x6ff870
// 00700e57  83c624               add esi, 0x24
// 00700e5a  3bf7                 cmp esi, edi
// 00700e5c  75f2                 jne 0x700e50
// 00700e5e  5f                   pop edi
// 00700e5f  5e                   pop esi
// 00700e60  c20800               ret 8

struct Callee {
    void f();
};

extern "C" void __stdcall iterate(void* start, void* end)
{
    if (start == end) return;
    void* p = start;
    do {
        static_cast<Callee*>(p)->f();
        p = (void*)((char*)p + 0x14);
    } while (p != end);
}
