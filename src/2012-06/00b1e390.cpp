// roc 2012-06 00b1e390  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e390
//
// 00b1e390  a1b005e500           mov eax, dword ptr [0xe505b0]
// 00b1e395  50                   push eax
// 00b1e396  e8793de6ff           call 0x982114
// 00b1e39b  83c404               add esp, 4
// 00b1e39e  c7058805e5002c3cb400 mov dword ptr [0xe50588], 0xb43c2c
// 00b1e3a8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e390(int);
void func_00b1e390()
{
    G4_func_00b1e390(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
