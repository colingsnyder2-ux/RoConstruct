// from server: 100% by Xemicl
// from server: 100% by intel
// roc 2012-06 00739170  unit: RBX::GuiTextButton  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00739170
//
// 00739170  8b442404             mov eax, dword ptr [esp + 4]
// 00739174  56                   push esi
// 00739175  8bf1                 mov esi, ecx
// 00739177  39865c030000         cmp dword ptr [esi + 0x35c], eax
// 0073917d  7428                 je 0x7391a7
// 0073917f  687447e300           push 0xe34774
// 00739184  89865c030000         mov dword ptr [esi + 0x35c], eax
// 0073918a  e811bccdff           call 0x414da0
// 0073918f  68b446e300           push 0xe346b4
// 00739194  8bce                 mov ecx, esi
// 00739196  e805bccdff           call 0x414da0
// 0073919b  680046e300           push 0xe34600
// 007391a0  8bce                 mov ecx, esi
// 007391a2  e8f9bbcdff           call 0x414da0
// 007391a7  5e                   pop esi
// 007391a8  c20400               ret 4

struct GuiTextButton {
    char pad[0x23c];
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
