// from server: 100% by nuck16
// from server: 95% by atomic.potato
// roc 2009-12 004526f0  unit: CRobloxControlColorSelector  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004526f0
//
// 004526f0  8b442404             mov eax, dword ptr [esp + 4]
// 004526f4  c70004010000         mov dword ptr [eax], 0x104
// 004526fa  c7400404010000       mov dword ptr [eax + 4], 0x104
// 00452701  c20800               ret 8

struct Size
{
    int cx;
    int cy;
    Size(int x, int y) { cx = x; cy = y; }
};

struct CRobloxControlColorSelector
{
    Size f(int arg);
};

Size CRobloxControlColorSelector::f(int)
{
    return Size(0x104, 0x104);
}
