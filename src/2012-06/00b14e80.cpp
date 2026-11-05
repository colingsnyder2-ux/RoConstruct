// roc 2012-06 00b14e80  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14e80
//
// 00b14e80  a1189fe200           mov eax, dword ptr [0xe29f18]
// 00b14e85  50                   push eax
// 00b14e86  e889d2e6ff           call 0x982114
// 00b14e8b  83c404               add esp, 4
// 00b14e8e  c705f09ee2002c3cb400 mov dword ptr [0xe29ef0], 0xb43c2c
// 00b14e98  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b14e80(int);
void func_00b14e80()
{
    G4_func_00b14e80(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
