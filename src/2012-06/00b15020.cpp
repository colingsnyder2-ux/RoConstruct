// roc 2012-06 00b15020  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15020
//
// 00b15020  a1c0a0e200           mov eax, dword ptr [0xe2a0c0]
// 00b15025  50                   push eax
// 00b15026  e8e9d0e6ff           call 0x982114
// 00b1502b  83c404               add esp, 4
// 00b1502e  c70598a0e2002c3cb400 mov dword ptr [0xe2a098], 0xb43c2c
// 00b15038  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15020(int);
void func_00b15020()
{
    G4_func_00b15020(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
