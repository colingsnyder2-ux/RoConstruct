// roc 2012-06 00b16ac0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16ac0
//
// 00b16ac0  a1a4f4e200           mov eax, dword ptr [0xe2f4a4]
// 00b16ac5  50                   push eax
// 00b16ac6  e849b6e6ff           call 0x982114
// 00b16acb  83c404               add esp, 4
// 00b16ace  c70578f4e2002c3cb400 mov dword ptr [0xe2f478], 0xb43c2c
// 00b16ad8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b16ac0(int);
void func_00b16ac0()
{
    G4_func_00b16ac0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
