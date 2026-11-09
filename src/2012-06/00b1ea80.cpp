// roc 2012-06 00b1ea80  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ea80
//
// 00b1ea80  a1b40ce500           mov eax, dword ptr [0xe50cb4]
// 00b1ea85  50                   push eax
// 00b1ea86  e88936e6ff           call 0x982114
// 00b1ea8b  83c404               add esp, 4
// 00b1ea8e  c7058c0ce5002c3cb400 mov dword ptr [0xe50c8c], 0xb43c2c
// 00b1ea98  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1ea80(int);
void func_00b1ea80()
{
    G4_func_00b1ea80(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
