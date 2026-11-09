// roc 2012-06 00b10bc0  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10bc0
//
// 00b10bc0  e82b1aecff           call 0x9d25f0
// 00b10bc5  50                   push eax
// 00b10bc6  e8d31ee7ff           call 0x982a9e
// 00b10bcb  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b10bc0();
extern int __stdcall G2_func_00b10bc0(int);
int func_00b10bc0()
{
    return G2_func_00b10bc0(G1_func_00b10bc0());
}
