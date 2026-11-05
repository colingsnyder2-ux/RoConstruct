// roc 2012-06 00b1f950  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f950
//
// 00b1f950  a11833e500           mov eax, dword ptr [0xe53318]
// 00b1f955  50                   push eax
// 00b1f956  e8b927e6ff           call 0x982114
// 00b1f95b  83c404               add esp, 4
// 00b1f95e  c705f032e5002c3cb400 mov dword ptr [0xe532f0], 0xb43c2c
// 00b1f968  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f950(int);
void func_00b1f950()
{
    G4_func_00b1f950(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
