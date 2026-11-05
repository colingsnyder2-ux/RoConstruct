// roc 2012-06 00b12ae0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12ae0
//
// 00b12ae0  b974c9e100           mov ecx, 0xe1c974
// 00b12ae5  e9c6fc9bff           jmp 0x4d27b0
// auto-matched from its assembly shape

struct T_func_00b12ae0 { void m(); };
extern T_func_00b12ae0 G1_func_00b12ae0;
void func_00b12ae0()
{
    G1_func_00b12ae0.m();
}
