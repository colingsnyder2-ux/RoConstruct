// roc 2012-06 00b1e8a0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e8a0
//
// 00b1e8a0  a1200ee500           mov eax, dword ptr [0xe50e20]
// 00b1e8a5  50                   push eax
// 00b1e8a6  e86938e6ff           call 0x982114
// 00b1e8ab  83c404               add esp, 4
// 00b1e8ae  c705f40de5002c3cb400 mov dword ptr [0xe50df4], 0xb43c2c
// 00b1e8b8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e8a0(int);
void func_00b1e8a0()
{
    G4_func_00b1e8a0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
