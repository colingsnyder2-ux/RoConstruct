// roc 2012-06 00b10ba0  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10ba0
//
// 00b10ba0  e87b18ecff           call 0x9d2420
// 00b10ba5  50                   push eax
// 00b10ba6  e8f31ee7ff           call 0x982a9e
// 00b10bab  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b10ba0();
extern int __stdcall G2_func_00b10ba0(int);
int func_00b10ba0()
{
    return G2_func_00b10ba0(G1_func_00b10ba0());
}
