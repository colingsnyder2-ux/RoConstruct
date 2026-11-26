// from server: 100% by Xemicl
// from server: 100% by tajop
// roc 2012-06 0045d200  unit: XBrickColorItem  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0045d200
//
// 0045d200  8b442408             mov eax, dword ptr [esp + 8]
// 0045d204  56                   push esi
// 0045d205  8bf1                 mov esi, ecx
// 0045d207  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0045d20b  50                   push eax
// 0045d20c  51                   push ecx
// 0045d20d  8bce                 mov ecx, esi
// 0045d20f  e8ecc4ffff           call 0x459700
// 0045d214  33c0                 xor eax, eax
// 0045d216  898630010000         mov dword ptr [esi + 0x130], eax
// 0045d21c  89862c010000         mov dword ptr [esi + 0x12c], eax
// 0045d222  898628010000         mov dword ptr [esi + 0x128], eax
// 0045d228  c7064457b500         mov dword ptr [esi], 0xb55744
// 0045d22e  c74620e456b500       mov dword ptr [esi + 0x20], 0xb556e4
// 0045d235  c7860c010000dc56b500 mov dword ptr [esi + 0x10c], 0xb556dc
// 0045d23f  8bc6                 mov eax, esi
// 0045d241  5e                   pop esi
// 0045d242  c20800               ret 8

struct B0 {
    virtual void f0();
    char pad0[0x1c];
};
struct B1 {
    virtual void f1();
    char pad1[0xe8];
};
struct B2 {
    virtual void f2();
    char pad2[0x18];
};
struct Base : B0, B1, B2 {
    Base(void* a, void* b);
};
struct Vec {
    void* first;
    void* last;
    void* end;
    Vec() { first = last = end = 0; }
};
struct XBrickColorItem : Base, Vec {
    XBrickColorItem(void* a, void* b);
};
XBrickColorItem::XBrickColorItem(void* a, void* b) : Base(a, b) {
}
