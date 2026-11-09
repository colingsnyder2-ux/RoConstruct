// roc 2012-06 00b20b70  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20b70
//
// 00b20b70  a1f85de500           mov eax, dword ptr [0xe55df8]
// 00b20b75  50                   push eax
// 00b20b76  e89915e6ff           call 0x982114
// 00b20b7b  83c404               add esp, 4
// 00b20b7e  c705d05de5002c3cb400 mov dword ptr [0xe55dd0], 0xb43c2c
// 00b20b88  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20b70(int);
void func_00b20b70()
{
    G4_func_00b20b70(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
