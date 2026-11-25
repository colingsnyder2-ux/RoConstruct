// from server: 88% by Xemicl
// from server: 100% by atomic.potato
// roc 2012-06 007391b0  unit: RBX::GuiTextButton  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007391b0
//
// 007391b0  8b442404             mov eax, dword ptr [esp + 4]
// 007391b4  56                   push esi
// 007391b5  8bf1                 mov esi, ecx
// 007391b7  398660030000         cmp dword ptr [esi + 0x360], eax
// 007391bd  7428                 je 0x7391e7
// 007391bf  684047e300           push 0xe34740
// 007391c4  898660030000         mov dword ptr [esi + 0x360], eax
// 007391ca  e8d1bbcdff           call 0x414da0
// 007391cf  68b446e300           push 0xe346b4
// 007391d4  8bce                 mov ecx, esi
// 007391d6  e8c5bbcdff           call 0x414da0
// 007391db  680046e300           push 0xe34600
// 007391e0  8bce                 mov ecx, esi
// 007391e2  e8b9bbcdff           call 0x414da0
// 007391e7  5e                   pop esi
// 007391e8  c20400               ret 4

struct GuiTextButton {
    char pad[0x360];
    int field_360;
    void sub_414da0(const void*);
    void set(int);
};

void GuiTextButton::set(int value)
{
    if (field_360 != value) {
        field_360 = value;
        sub_414da0((const void*)0xe34740);
        sub_414da0((const void*)0xe346b4);
        sub_414da0((const void*)0xe34600);
    }
}
