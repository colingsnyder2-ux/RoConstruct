// from server: 100% by EspClaude
// roc 2009-06 00445460  unit: CIDEDocManager  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00445460
//
// 00445460  8b442414             mov eax, dword ptr [esp + 0x14]
// 00445464  85c0                 test eax, eax
// 00445466  7503                 jne 0x44546b
// 00445468  8b4124               mov eax, dword ptr [ecx + 0x24]
// 0044546b  89442414             mov dword ptr [esp + 0x14], eax
// 0044546f  e9b2412d00           jmp 0x719626
// copied from an identical function in another client (function ?f@CIDEDocManager@ns_ROCX00000e@@QAEHHHHHH@Z)

namespace ns_ROCX00000e {
struct CIDEDocManager {
    unsigned char padding[36];
    int defaultValue;

    int forward(int a, int b, int c, int d, int e);
    int f(int a, int b, int c, int d, int e);
};

int CIDEDocManager::f(int a, int b, int c, int d, int e)
{
    if (!e)
        e = defaultValue;
    return forward(a, b, c, d, e);
}
}
