// roc 2012-06 00b10650  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10650
//
// 00b10650  e8db82ebff           call 0x9c8930
// 00b10655  50                   push eax
// 00b10656  e84324e7ff           call 0x982a9e
// 00b1065b  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b10650();
extern int __stdcall G2_func_00b10650(int);
int func_00b10650()
{
    return G2_func_00b10650(G1_func_00b10650());
}
