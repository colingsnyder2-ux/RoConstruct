// roc 2012-06 00b1d2f0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d2f0
//
// 00b1d2f0  a154e7e400           mov eax, dword ptr [0xe4e754]
// 00b1d2f5  50                   push eax
// 00b1d2f6  e8194ee6ff           call 0x982114
// 00b1d2fb  83c404               add esp, 4
// 00b1d2fe  c7052ce7e4002c3cb400 mov dword ptr [0xe4e72c], 0xb43c2c
// 00b1d308  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1d2f0(int);
void func_00b1d2f0()
{
    G4_func_00b1d2f0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
