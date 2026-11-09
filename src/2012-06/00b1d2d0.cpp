// roc 2012-06 00b1d2d0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d2d0
//
// 00b1d2d0  a160e5e400           mov eax, dword ptr [0xe4e560]
// 00b1d2d5  50                   push eax
// 00b1d2d6  e8394ee6ff           call 0x982114
// 00b1d2db  83c404               add esp, 4
// 00b1d2de  c70538e5e4002c3cb400 mov dword ptr [0xe4e538], 0xb43c2c
// 00b1d2e8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1d2d0(int);
void func_00b1d2d0()
{
    G4_func_00b1d2d0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
