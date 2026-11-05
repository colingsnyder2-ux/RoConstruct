// roc 2012-06 00b10bb0  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10bb0
//
// 00b10bb0  e80b1aecff           call 0x9d25c0
// 00b10bb5  50                   push eax
// 00b10bb6  e8e31ee7ff           call 0x982a9e
// 00b10bbb  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b10bb0();
extern int __stdcall G2_func_00b10bb0(int);
int func_00b10bb0()
{
    return G2_func_00b10bb0(G1_func_00b10bb0());
}
