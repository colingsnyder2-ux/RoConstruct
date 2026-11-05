// roc 2012-06 00b16b20  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16b20
//
// 00b16b20  a1ecefe200           mov eax, dword ptr [0xe2efec]
// 00b16b25  50                   push eax
// 00b16b26  e8e9b5e6ff           call 0x982114
// 00b16b2b  83c404               add esp, 4
// 00b16b2e  c705c0efe2002c3cb400 mov dword ptr [0xe2efc0], 0xb43c2c
// 00b16b38  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b16b20(int);
void func_00b16b20()
{
    G4_func_00b16b20(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
