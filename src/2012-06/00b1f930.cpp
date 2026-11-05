// roc 2012-06 00b1f930  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f930
//
// 00b1f930  a10832e500           mov eax, dword ptr [0xe53208]
// 00b1f935  50                   push eax
// 00b1f936  e8d927e6ff           call 0x982114
// 00b1f93b  83c404               add esp, 4
// 00b1f93e  c705e031e5002c3cb400 mov dword ptr [0xe531e0], 0xb43c2c
// 00b1f948  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f930(int);
void func_00b1f930()
{
    G4_func_00b1f930(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
