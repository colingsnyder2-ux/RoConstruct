// roc 2012-06 00b1c710  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c710
//
// 00b1c710  a1dcb3e400           mov eax, dword ptr [0xe4b3dc]
// 00b1c715  50                   push eax
// 00b1c716  e8f959e6ff           call 0x982114
// 00b1c71b  83c404               add esp, 4
// 00b1c71e  c705b4b3e4002c3cb400 mov dword ptr [0xe4b3b4], 0xb43c2c
// 00b1c728  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1c710(int);
void func_00b1c710()
{
    G4_func_00b1c710(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
