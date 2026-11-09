// roc 2012-06 00b10bd0  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10bd0
//
// 00b10bd0  e82b1aecff           call 0x9d2600
// 00b10bd5  50                   push eax
// 00b10bd6  e8c31ee7ff           call 0x982a9e
// 00b10bdb  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b10bd0();
extern int __stdcall G2_func_00b10bd0(int);
int func_00b10bd0()
{
    return G2_func_00b10bd0(G1_func_00b10bd0());
}
