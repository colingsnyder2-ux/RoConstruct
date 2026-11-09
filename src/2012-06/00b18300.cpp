// roc 2012-06 00b18300  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18300
//
// 00b18300  a11057e300           mov eax, dword ptr [0xe35710]
// 00b18305  50                   push eax
// 00b18306  e8099ee6ff           call 0x982114
// 00b1830b  83c404               add esp, 4
// 00b1830e  c705e856e3002c3cb400 mov dword ptr [0xe356e8], 0xb43c2c
// 00b18318  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b18300(int);
void func_00b18300()
{
    G4_func_00b18300(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
