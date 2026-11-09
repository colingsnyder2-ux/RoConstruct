// roc 2012-06 00b15bf0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15bf0
//
// 00b15bf0  a1b8b4e200           mov eax, dword ptr [0xe2b4b8]
// 00b15bf5  50                   push eax
// 00b15bf6  e819c5e6ff           call 0x982114
// 00b15bfb  83c404               add esp, 4
// 00b15bfe  c70590b4e2002c3cb400 mov dword ptr [0xe2b490], 0xb43c2c
// 00b15c08  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15bf0(int);
void func_00b15bf0()
{
    G4_func_00b15bf0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
