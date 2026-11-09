// roc 2012-06 00b15500  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15500
//
// 00b15500  a154a0e200           mov eax, dword ptr [0xe2a054]
// 00b15505  50                   push eax
// 00b15506  e809cce6ff           call 0x982114
// 00b1550b  83c404               add esp, 4
// 00b1550e  c7052ca0e2002c3cb400 mov dword ptr [0xe2a02c], 0xb43c2c
// 00b15518  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15500(int);
void func_00b15500()
{
    G4_func_00b15500(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
