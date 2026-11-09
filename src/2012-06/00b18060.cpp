// roc 2012-06 00b18060  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18060
//
// 00b18060  a18046e300           mov eax, dword ptr [0xe34680]
// 00b18065  50                   push eax
// 00b18066  e8a9a0e6ff           call 0x982114
// 00b1806b  83c404               add esp, 4
// 00b1806e  c7055846e3002c3cb400 mov dword ptr [0xe34658], 0xb43c2c
// 00b18078  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b18060(int);
void func_00b18060()
{
    G4_func_00b18060(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
