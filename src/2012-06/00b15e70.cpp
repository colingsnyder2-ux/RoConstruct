// roc 2012-06 00b15e70  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15e70
//
// 00b15e70  a1a8c2e200           mov eax, dword ptr [0xe2c2a8]
// 00b15e75  50                   push eax
// 00b15e76  e899c2e6ff           call 0x982114
// 00b15e7b  83c404               add esp, 4
// 00b15e7e  c70580c2e2002c3cb400 mov dword ptr [0xe2c280], 0xb43c2c
// 00b15e88  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15e70(int);
void func_00b15e70()
{
    G4_func_00b15e70(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
