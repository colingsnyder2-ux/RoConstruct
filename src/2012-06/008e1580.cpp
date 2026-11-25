// from server: 100% by Xemicl
// from server: 100% by tajop
// roc 2012-06 00889d40  unit: RBX::VRelativePanel::?$NonFactoryProduct  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00889d40
//
// 00889d40  6aff                 push -1
// 00889d42  687810ad00           push 0xad1078
// 00889d47  64a100000000         mov eax, dword ptr fs:[0]
// 00889d4d  50                   push eax
// 00889d4e  64892500000000       mov dword ptr fs:[0], esp
// 00889d55  51                   push ecx
// 00889d56  56                   push esi
// 00889d57  8bf1                 mov esi, ecx
// 00889d59  89742404             mov dword ptr [esp + 4], esi
// 00889d5d  e8fe20e8ff           call 0x70be60
// 00889d62  c706fc97bd00         mov dword ptr [esi], 0xbd97fc
// 00889d68  c74604f097bd00       mov dword ptr [esi + 4], 0xbd97f0
// 00889d6f  c74618e497bd00       mov dword ptr [esi + 0x18], 0xbd97e4
// 00889d76  c7461cd897bd00       mov dword ptr [esi + 0x1c], 0xbd97d8
// 00889d7d  c78680000000d097bd00 mov dword ptr [esi + 0x80], 0xbd97d0
// 00889d87  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00889d8f  e89c89efff           call 0x782730
// 00889d94  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00889d98  894628               mov dword ptr [esi + 0x28], eax
// 00889d9b  ff05288be400         inc dword ptr [0xe48b28]
// 00889da1  8bc6                 mov eax, esi
// 00889da3  5e                   pop esi
// 00889da4  64890d00000000       mov dword ptr fs:[0], ecx
// 00889dab  83c410               add esp, 0x10
// 00889dae  c3                   ret 

struct Vt0 { virtual void f0(); };
struct Vt4 { virtual void f4(); int pad4[4]; };
struct Vt18 { virtual void f18(); };
struct Vt1c { virtual void f1c(); int pad20[2]; int value28; int pad2c[21]; };
struct Vt80 { virtual void f80(); };

struct RelativePanelBase : Vt0, Vt4, Vt18, Vt1c, Vt80 {
    RelativePanelBase();
};

struct Guard {
    int value;
    Guard() {}
    ~Guard();
};

int getValue();

struct NonFactoryProduct : RelativePanelBase {
    static int counter;
    Guard guard;
    NonFactoryProduct();
};

NonFactoryProduct::NonFactoryProduct() {
    value28 = getValue();
    ++counter;
}
