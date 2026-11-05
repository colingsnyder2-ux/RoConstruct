// roc 2012-06 00b14030  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14030
//
// 00b14030  a1903be200           mov eax, dword ptr [0xe23b90]
// 00b14035  50                   push eax
// 00b14036  e8d9e0e6ff           call 0x982114
// 00b1403b  83c404               add esp, 4
// 00b1403e  c705683be2002c3cb400 mov dword ptr [0xe23b68], 0xb43c2c
// 00b14048  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b14030(int);
void func_00b14030()
{
    G4_func_00b14030(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
