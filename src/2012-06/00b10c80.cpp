// roc 2012-06 00b10c80  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10c80
//
// 00b10c80  e86b8feeff           call 0x9f9bf0
// 00b10c85  50                   push eax
// 00b10c86  e8131ee7ff           call 0x982a9e
// 00b10c8b  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b10c80();
extern int __stdcall G2_func_00b10c80(int);
int func_00b10c80()
{
    return G2_func_00b10c80(G1_func_00b10c80());
}
