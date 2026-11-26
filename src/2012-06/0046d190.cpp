// from server: 100% by Xemicl
// roc 2012-06 0046d190  unit: CIDEDocManager  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0046d190
//
// 0046d190  8b442414             mov eax, dword ptr [esp + 0x14]
// 0046d194  85c0                 test eax, eax
// 0046d196  7503                 jne 0x46d19b
// 0046d198  8b4124               mov eax, dword ptr [ecx + 0x24]
// 0046d19b  89442414             mov dword ptr [esp + 0x14], eax
// 0046d19f  e93a5b5100           jmp 0x982cde
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