// roc 2012-06 00b1bfe0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1bfe0
//
// 00b1bfe0  a18ca6e400           mov eax, dword ptr [0xe4a68c]
// 00b1bfe5  50                   push eax
// 00b1bfe6  e82961e6ff           call 0x982114
// 00b1bfeb  83c404               add esp, 4
// 00b1bfee  c70560a6e4002c3cb400 mov dword ptr [0xe4a660], 0xb43c2c
// 00b1bff8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1bfe0(int);
void func_00b1bfe0()
{
    G4_func_00b1bfe0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
