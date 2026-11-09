// roc 2012-06 00b15810  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15810
//
// 00b15810  a1dca2e200           mov eax, dword ptr [0xe2a2dc]
// 00b15815  50                   push eax
// 00b15816  e8f9c8e6ff           call 0x982114
// 00b1581b  83c404               add esp, 4
// 00b1581e  c705b4a2e2002c3cb400 mov dword ptr [0xe2a2b4], 0xb43c2c
// 00b15828  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15810(int);
void func_00b15810()
{
    G4_func_00b15810(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
