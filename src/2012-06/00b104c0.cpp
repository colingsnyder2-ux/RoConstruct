// roc 2012-06 00b104c0  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b104c0
//
// 00b104c0  e8db24e8ff           call 0x9929a0
// 00b104c5  50                   push eax
// 00b104c6  e8d325e7ff           call 0x982a9e
// 00b104cb  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b104c0();
extern int __stdcall G2_func_00b104c0(int);
int func_00b104c0()
{
    return G2_func_00b104c0(G1_func_00b104c0());
}
