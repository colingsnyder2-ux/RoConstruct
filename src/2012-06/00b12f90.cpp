// roc 2012-06 00b12f90  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12f90
//
// 00b12f90  a1f80ee200           mov eax, dword ptr [0xe20ef8]
// 00b12f95  50                   push eax
// 00b12f96  e879f1e6ff           call 0x982114
// 00b12f9b  83c404               add esp, 4
// 00b12f9e  c705cc0ee2002c3cb400 mov dword ptr [0xe20ecc], 0xb43c2c
// 00b12fa8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b12f90(int);
void func_00b12f90()
{
    G4_func_00b12f90(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
