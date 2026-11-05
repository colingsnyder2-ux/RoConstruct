// roc 2012-06 00b15e50  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15e50
//
// 00b15e50  a1d4c2e200           mov eax, dword ptr [0xe2c2d4]
// 00b15e55  50                   push eax
// 00b15e56  e8b9c2e6ff           call 0x982114
// 00b15e5b  83c404               add esp, 4
// 00b15e5e  c705acc2e2002c3cb400 mov dword ptr [0xe2c2ac], 0xb43c2c
// 00b15e68  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15e50(int);
void func_00b15e50()
{
    G4_func_00b15e50(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
