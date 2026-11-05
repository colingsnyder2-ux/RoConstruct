// roc 2012-06 00b10c40  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10c40
//
// 00b10c40  e8abb9ecff           call 0x9dc5f0
// 00b10c45  50                   push eax
// 00b10c46  e8531ee7ff           call 0x982a9e
// 00b10c4b  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b10c40();
extern int __stdcall G2_func_00b10c40(int);
int func_00b10c40()
{
    return G2_func_00b10c40(G1_func_00b10c40());
}
