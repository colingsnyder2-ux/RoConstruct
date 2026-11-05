// roc 2012-06 00b14110  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14110
//
// 00b14110  a1b43ae200           mov eax, dword ptr [0xe23ab4]
// 00b14115  50                   push eax
// 00b14116  e8f9dfe6ff           call 0x982114
// 00b1411b  83c404               add esp, 4
// 00b1411e  c7058c3ae2002c3cb400 mov dword ptr [0xe23a8c], 0xb43c2c
// 00b14128  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b14110(int);
void func_00b14110()
{
    G4_func_00b14110(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
