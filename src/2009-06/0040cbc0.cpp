// from server: 100% by EspClaude
// roc 2009-06 0040cbc0  unit: CIDEBrowserView  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0040cbc0
//
// 0040cbc0  56                   push esi
// 0040cbc1  57                   push edi
// 0040cbc2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0040cbc6  57                   push edi
// 0040cbc7  8bf1                 mov esi, ecx
// 0040cbc9  e824c23000           call 0x718df2
// 0040cbce  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 0040cbd1  85c9                 test ecx, ecx
// 0040cbd3  740d                 je 0x40cbe2
// 0040cbd5  8b01                 mov eax, dword ptr [ecx]
// 0040cbd7  8b5058               mov edx, dword ptr [eax + 0x58]
// 0040cbda  57                   push edi
// 0040cbdb  ffd2                 call edx
// 0040cbdd  5f                   pop edi
// 0040cbde  5e                   pop esi
// 0040cbdf  c20400               ret 4
// 0040cbe2  8bce                 mov ecx, esi
// 0040cbe4  e83dc13000           call 0x718d26
// 0040cbe9  85c0                 test eax, eax
// 0040cbeb  740f                 je 0x40cbfc
// 0040cbed  57                   push edi
// 0040cbee  8bce                 mov ecx, esi
// 0040cbf0  e831c13000           call 0x718d26
// 0040cbf5  8bc8                 mov ecx, eax
// 0040cbf7  e8f0c13000           call 0x718dec
// 0040cbfc  5f                   pop edi
// 0040cbfd  5e                   pop esi
// 0040cbfe  c20400               ret 4
// copied from an identical function in another client (function ?method@CBrowserView@ns_ROCX000004@@QAEXH@Z)

namespace ns_ROCX000004 {
struct Receiver {
    void forward(int value);
};

struct CBrowserView {
    char padding[0x54];
    void* receiver;

    void initial(int value);
    Receiver* lookup();
    void method(int value);
};

void CBrowserView::method(int value) {
    initial(value);
    if (receiver) {
        void* p = receiver;
        void** table = *(void***)p;
        void (__thiscall *fn)(void*, int) =
            (void (__thiscall *)(void*, int))table[0x58 / 4];
        fn(p, value);
    } else if (lookup()) {
        lookup()->forward(value);
    }
}
}
