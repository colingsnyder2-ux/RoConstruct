// roc 2012-06 00b12020  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12020
//
// 00b12020  a12898e100           mov eax, dword ptr [0xe19828]
// 00b12025  50                   push eax
// 00b12026  e8e900e7ff           call 0x982114
// 00b1202b  83c404               add esp, 4
// 00b1202e  c7050098e1002c3cb400 mov dword ptr [0xe19800], 0xb43c2c
// 00b12038  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b12020(int);
void func_00b12020()
{
    G4_func_00b12020(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
