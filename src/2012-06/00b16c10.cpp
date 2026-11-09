// roc 2012-06 00b16c10  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16c10
//
// 00b16c10  a164ede200           mov eax, dword ptr [0xe2ed64]
// 00b16c15  50                   push eax
// 00b16c16  e8f9b4e6ff           call 0x982114
// 00b16c1b  83c404               add esp, 4
// 00b16c1e  c7053cede2002c3cb400 mov dword ptr [0xe2ed3c], 0xb43c2c
// 00b16c28  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b16c10(int);
void func_00b16c10()
{
    G4_func_00b16c10(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
