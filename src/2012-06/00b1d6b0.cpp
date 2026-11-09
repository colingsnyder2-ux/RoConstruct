// roc 2012-06 00b1d6b0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d6b0
//
// 00b1d6b0  a124f2e400           mov eax, dword ptr [0xe4f224]
// 00b1d6b5  50                   push eax
// 00b1d6b6  e8594ae6ff           call 0x982114
// 00b1d6bb  83c404               add esp, 4
// 00b1d6be  c705fcf1e4002c3cb400 mov dword ptr [0xe4f1fc], 0xb43c2c
// 00b1d6c8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1d6b0(int);
void func_00b1d6b0()
{
    G4_func_00b1d6b0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
