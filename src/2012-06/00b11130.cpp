// roc 2012-06 00b11130  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11130
//
// 00b11130  e84b9af3ff           call 0xa4ab80
// 00b11135  50                   push eax
// 00b11136  e86319e7ff           call 0x982a9e
// 00b1113b  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b11130();
extern int __stdcall G2_func_00b11130(int);
int func_00b11130()
{
    return G2_func_00b11130(G1_func_00b11130());
}
