// roc 2012-06 00b10610  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10610
//
// 00b10610  e80b8feaff           call 0x9b9520
// 00b10615  50                   push eax
// 00b10616  e88324e7ff           call 0x982a9e
// 00b1061b  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b10610();
extern int __stdcall G2_func_00b10610(int);
int func_00b10610()
{
    return G2_func_00b10610(G1_func_00b10610());
}
