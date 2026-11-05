// roc 2012-06 00b1d390  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d390
//
// 00b1d390  a110e6e400           mov eax, dword ptr [0xe4e610]
// 00b1d395  50                   push eax
// 00b1d396  e8794de6ff           call 0x982114
// 00b1d39b  83c404               add esp, 4
// 00b1d39e  c705e8e5e4002c3cb400 mov dword ptr [0xe4e5e8], 0xb43c2c
// 00b1d3a8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1d390(int);
void func_00b1d390()
{
    G4_func_00b1d390(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
