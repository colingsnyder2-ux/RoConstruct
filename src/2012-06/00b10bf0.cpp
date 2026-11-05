// roc 2012-06 00b10bf0  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10bf0
//
// 00b10bf0  e89b1aecff           call 0x9d2690
// 00b10bf5  50                   push eax
// 00b10bf6  e8a31ee7ff           call 0x982a9e
// 00b10bfb  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b10bf0();
extern int __stdcall G2_func_00b10bf0(int);
int func_00b10bf0()
{
    return G2_func_00b10bf0(G1_func_00b10bf0());
}
