// roc 2012-06 00b14e20  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14e20
//
// 00b14e20  a1f495e200           mov eax, dword ptr [0xe295f4]
// 00b14e25  50                   push eax
// 00b14e26  e8e9d2e6ff           call 0x982114
// 00b14e2b  83c404               add esp, 4
// 00b14e2e  c705cc95e2002c3cb400 mov dword ptr [0xe295cc], 0xb43c2c
// 00b14e38  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b14e20(int);
void func_00b14e20()
{
    G4_func_00b14e20(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
