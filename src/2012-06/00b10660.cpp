// roc 2012-06 00b10660  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10660
//
// 00b10660  e87ba0ebff           call 0x9ca6e0
// 00b10665  50                   push eax
// 00b10666  e83324e7ff           call 0x982a9e
// 00b1066b  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b10660();
extern int __stdcall G2_func_00b10660(int);
int func_00b10660()
{
    return G2_func_00b10660(G1_func_00b10660());
}
