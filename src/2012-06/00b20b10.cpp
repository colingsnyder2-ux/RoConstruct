// roc 2012-06 00b20b10  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20b10
//
// 00b20b10  a1e85ce500           mov eax, dword ptr [0xe55ce8]
// 00b20b15  50                   push eax
// 00b20b16  e8f915e6ff           call 0x982114
// 00b20b1b  83c404               add esp, 4
// 00b20b1e  c705c05ce5002c3cb400 mov dword ptr [0xe55cc0], 0xb43c2c
// 00b20b28  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20b10(int);
void func_00b20b10()
{
    G4_func_00b20b10(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
