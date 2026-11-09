// roc 2012-06 00b11210  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11210
//
// 00b11210  e81b5af6ff           call 0xa76c30
// 00b11215  50                   push eax
// 00b11216  e88318e7ff           call 0x982a9e
// 00b1121b  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b11210();
extern int __stdcall G2_func_00b11210(int);
int func_00b11210()
{
    return G2_func_00b11210(G1_func_00b11210());
}
