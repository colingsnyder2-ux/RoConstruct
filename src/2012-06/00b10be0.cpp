// roc 2012-06 00b10be0  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10be0
//
// 00b10be0  e83b1aecff           call 0x9d2620
// 00b10be5  50                   push eax
// 00b10be6  e8b31ee7ff           call 0x982a9e
// 00b10beb  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b10be0();
extern int __stdcall G2_func_00b10be0(int);
int func_00b10be0()
{
    return G2_func_00b10be0(G1_func_00b10be0());
}
