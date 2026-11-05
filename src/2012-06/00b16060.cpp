// roc 2012-06 00b16060  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16060
//
// 00b16060  a188d1e200           mov eax, dword ptr [0xe2d188]
// 00b16065  50                   push eax
// 00b16066  e8a9c0e6ff           call 0x982114
// 00b1606b  83c404               add esp, 4
// 00b1606e  c70560d1e2002c3cb400 mov dword ptr [0xe2d160], 0xb43c2c
// 00b16078  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b16060(int);
void func_00b16060()
{
    G4_func_00b16060(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
