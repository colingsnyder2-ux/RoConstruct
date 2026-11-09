// roc 2012-06 00b15280  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15280
//
// 00b15280  a1ec96e200           mov eax, dword ptr [0xe296ec]
// 00b15285  50                   push eax
// 00b15286  e889cee6ff           call 0x982114
// 00b1528b  83c404               add esp, 4
// 00b1528e  c705c496e2002c3cb400 mov dword ptr [0xe296c4], 0xb43c2c
// 00b15298  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15280(int);
void func_00b15280()
{
    G4_func_00b15280(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
