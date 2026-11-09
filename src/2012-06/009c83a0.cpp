// roc 2012-06 009c83a0  unit: CXTPDockingPaneManager  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009c83a0
//
// 009c83a0  56                   push esi
// 009c83a1  8bf1                 mov esi, ecx
// 009c83a3  8b8ed4000000         mov ecx, dword ptr [esi + 0xd4]
// 009c83a9  8b01                 mov eax, dword ptr [ecx]
// 009c83ab  8b5068               mov edx, dword ptr [eax + 0x68]
// 009c83ae  ffd2                 call edx
// 009c83b0  8bce                 mov ecx, esi
// 009c83b2  e819f7ffff           call 0x9c7ad0
// 009c83b7  5e                   pop esi
// 009c83b8  c20800               ret 8
// copied from an identical function in another client (function ?func@CXTPDockingPaneManager@ns_ROCX000000@@QAEXHH@Z)

namespace ns_ROCX000000 {
struct Inner {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
};

struct CXTPDockingPaneManager {
    char pad[0xd4];
    Inner* field_d4;
    void sub_66f6c0();
    void func(int a, int b);
};

void CXTPDockingPaneManager::func(int a, int b) {
    field_d4->vf26();
    sub_66f6c0();
}
}
