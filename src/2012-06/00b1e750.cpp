// roc 2012-06 00b1e750  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e750
//
// 00b1e750  a1f809e500           mov eax, dword ptr [0xe509f8]
// 00b1e755  50                   push eax
// 00b1e756  e8b939e6ff           call 0x982114
// 00b1e75b  83c404               add esp, 4
// 00b1e75e  c705cc09e5002c3cb400 mov dword ptr [0xe509cc], 0xb43c2c
// 00b1e768  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e750(int);
void func_00b1e750()
{
    G4_func_00b1e750(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
