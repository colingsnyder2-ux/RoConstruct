// roc 2012-06 00b11610  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11610
//
// 00b11610  a1c47de100           mov eax, dword ptr [0xe17dc4]
// 00b11615  50                   push eax
// 00b11616  e8f90ae7ff           call 0x982114
// 00b1161b  83c404               add esp, 4
// 00b1161e  c7059c7de1002c3cb400 mov dword ptr [0xe17d9c], 0xb43c2c
// 00b11628  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b11610(int);
void func_00b11610()
{
    G4_func_00b11610(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
