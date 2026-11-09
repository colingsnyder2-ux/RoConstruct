// roc 2012-06 00b1d910  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d910
//
// 00b1d910  a13cf3e400           mov eax, dword ptr [0xe4f33c]
// 00b1d915  50                   push eax
// 00b1d916  e8f947e6ff           call 0x982114
// 00b1d91b  83c404               add esp, 4
// 00b1d91e  c70514f3e4002c3cb400 mov dword ptr [0xe4f314], 0xb43c2c
// 00b1d928  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1d910(int);
void func_00b1d910()
{
    G4_func_00b1d910(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
