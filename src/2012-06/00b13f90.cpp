// roc 2012-06 00b13f90  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13f90
//
// 00b13f90  a1e83be200           mov eax, dword ptr [0xe23be8]
// 00b13f95  50                   push eax
// 00b13f96  e879e1e6ff           call 0x982114
// 00b13f9b  83c404               add esp, 4
// 00b13f9e  c705c03be2002c3cb400 mov dword ptr [0xe23bc0], 0xb43c2c
// 00b13fa8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b13f90(int);
void func_00b13f90()
{
    G4_func_00b13f90(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
