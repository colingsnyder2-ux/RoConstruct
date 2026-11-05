// roc 2012-06 00b11220  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11220
//
// 00b11220  e84b5af6ff           call 0xa76c70
// 00b11225  50                   push eax
// 00b11226  e87318e7ff           call 0x982a9e
// 00b1122b  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b11220();
extern int __stdcall G2_func_00b11220(int);
int func_00b11220()
{
    return G2_func_00b11220(G1_func_00b11220());
}
