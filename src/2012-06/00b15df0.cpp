// roc 2012-06 00b15df0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15df0
//
// 00b15df0  a150c5e200           mov eax, dword ptr [0xe2c550]
// 00b15df5  50                   push eax
// 00b15df6  e819c3e6ff           call 0x982114
// 00b15dfb  83c404               add esp, 4
// 00b15dfe  c70524c5e2002c3cb400 mov dword ptr [0xe2c524], 0xb43c2c
// 00b15e08  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15df0(int);
void func_00b15df0()
{
    G4_func_00b15df0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
