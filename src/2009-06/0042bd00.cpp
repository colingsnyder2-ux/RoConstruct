// from server: 100% by EspClaude
// from server: 97% by EspClaude
// roc 2009-06 0042bd00  unit: RBX::$$A6AXVBrickColor::?$signal::slot  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0042bd00
//
// 0042bd00  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0042bd04  56                   push esi
// 0042bd05  57                   push edi
// 0042bd06  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0042bd0a  8bf1                 mov esi, ecx
// 0042bd0c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0042bd10  50                   push eax
// 0042bd11  51                   push ecx
// 0042bd12  57                   push edi
// 0042bd13  8bce                 mov ecx, esi
// 0042bd15  e8b0d72e00           call 0x7194ca
// 0042bd1a  80befc00000000       cmp byte ptr [esi + 0xfc], 0
// 0042bd21  741d                 je 0x42bd40
// 0042bd23  80befe00000000       cmp byte ptr [esi + 0xfe], 0
// 0042bd2a  7514                 jne 0x42bd40
// 0042bd2c  85ff                 test edi, edi
// 0042bd2e  7410                 je 0x42bd40
// 0042bd30  8bce                 mov ecx, esi
// 0042bd32  e8c9fbffff           call 0x42b900
// 0042bd37  6a09                 push 9
// 0042bd39  8bce                 mov ecx, esi
// 0042bd3b  e8e0cf2e00           call 0x718d20
// 0042bd40  5f                   pop edi
// 0042bd41  5e                   pop esi
// 0042bd42  c20c00               ret 0xc

// from server: 100% by colin
// roc 2008-06 00431bf0  unit: CDataModelPropGrid  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00431bf0
//
// 00431bf0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00431bf4  56                   push esi
// 00431bf5  57                   push edi
// 00431bf6  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00431bfa  8bf1                 mov esi, ecx
// 00431bfc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00431c00  50                   push eax
// 00431c01  51                   push ecx
// 00431c02  57                   push edi
// 00431c03  8bce                 mov ecx, esi
// 00431c05  e848f42600           call 0x6a1052
// 00431c0a  80bef800000000       cmp byte ptr [esi + 0xf8], 0
// 00431c11  741d                 je 0x431c30
// 00431c13  80befa00000000       cmp byte ptr [esi + 0xfa], 0
// 00431c1a  7514                 jne 0x431c30
// 00431c1c  85ff                 test edi, edi
// 00431c1e  7410                 je 0x431c30
// 00431c20  8bce                 mov ecx, esi
// 00431c22  e889fcffff           call 0x4318b0
// 00431c27  6a09                 push 9
// 00431c29  8bce                 mov ecx, esi
// 00431c2b  e83eed2600           call 0x6a096e
// 00431c30  5f                   pop edi
// 00431c31  5e                   pop esi
// 00431c32  c20c00               ret 0xc

struct CDataModelPropGrid
{
    char pad[0xfc];
    char field_f8;
    char pad2;
    char field_fa;
    void sub_6a1052(int, int, int);
    void sub_4318b0();
    void sub_6a096e(int);
    void func_431bf0(int, int, int);
};

void CDataModelPropGrid::func_431bf0(int a, int b, int c)
{
    sub_6a1052(a, b, c);
    if (field_f8 != 0 && field_fa == 0 && a != 0)
    {
        sub_4318b0();
        sub_6a096e(9);
    }
}
