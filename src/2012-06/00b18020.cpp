// roc 2012-06 00b18020  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18020
//
// 00b18020  a1fc45e300           mov eax, dword ptr [0xe345fc]
// 00b18025  50                   push eax
// 00b18026  e8e9a0e6ff           call 0x982114
// 00b1802b  83c404               add esp, 4
// 00b1802e  c705d445e3002c3cb400 mov dword ptr [0xe345d4], 0xb43c2c
// 00b18038  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b18020(int);
void func_00b18020()
{
    G4_func_00b18020(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
