// from server: 100% by Xemicl
// roc 2012-06 00415430  unit: CIDEBrowserView  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00415430
//
// 00415430  56                   push esi
// 00415431  57                   push edi
// 00415432  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00415436  57                   push edi
// 00415437  8bf1                 mov esi, ecx
// 00415439  e884d05600           call 0x9824c2
// 0041543e  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 00415441  85c9                 test ecx, ecx
// 00415443  740d                 je 0x415452
// 00415445  8b01                 mov eax, dword ptr [ecx]
// 00415447  8b5058               mov edx, dword ptr [eax + 0x58]
// 0041544a  57                   push edi
// 0041544b  ffd2                 call edx
// 0041544d  5f                   pop edi
// 0041544e  5e                   pop esi
// 0041544f  c20400               ret 4
// 00415452  8bce                 mov ecx, esi
// 00415454  e857d05600           call 0x9824b0
// 00415459  85c0                 test eax, eax
// 0041545b  740f                 je 0x41546c
// 0041545d  57                   push edi
// 0041545e  8bce                 mov ecx, esi
// 00415460  e84bd05600           call 0x9824b0
// 00415465  8bc8                 mov ecx, eax
// 00415467  e850d05600           call 0x9824bc
// 0041546c  5f                   pop edi
// 0041546d  5e                   pop esi
// 0041546e  c20400               ret 4
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