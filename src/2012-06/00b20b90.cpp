// roc 2012-06 00b20b90  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20b90
//
// 00b20b90  a1245ee500           mov eax, dword ptr [0xe55e24]
// 00b20b95  50                   push eax
// 00b20b96  e87915e6ff           call 0x982114
// 00b20b9b  83c404               add esp, 4
// 00b20b9e  c705fc5de5002c3cb400 mov dword ptr [0xe55dfc], 0xb43c2c
// 00b20ba8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20b90(int);
void func_00b20b90()
{
    G4_func_00b20b90(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
