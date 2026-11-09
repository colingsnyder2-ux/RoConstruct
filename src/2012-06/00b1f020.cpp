// roc 2012-06 00b1f020  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f020
//
// 00b1f020  a16c21e500           mov eax, dword ptr [0xe5216c]
// 00b1f025  50                   push eax
// 00b1f026  e8e930e6ff           call 0x982114
// 00b1f02b  83c404               add esp, 4
// 00b1f02e  c7054421e5002c3cb400 mov dword ptr [0xe52144], 0xb43c2c
// 00b1f038  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f020(int);
void func_00b1f020()
{
    G4_func_00b1f020(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
