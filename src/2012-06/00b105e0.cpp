// roc 2012-06 00b105e0  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b105e0
//
// 00b105e0  e88b66eaff           call 0x9b6c70
// 00b105e5  50                   push eax
// 00b105e6  e8b324e7ff           call 0x982a9e
// 00b105eb  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b105e0();
extern int __stdcall G2_func_00b105e0(int);
int func_00b105e0()
{
    return G2_func_00b105e0(G1_func_00b105e0());
}
