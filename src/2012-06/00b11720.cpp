// roc 2012-06 00b11720  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11720
//
// 00b11720  b9bc7ce100           mov ecx, 0xe17cbc
// 00b11725  e9760890ff           jmp 0x411fa0
// auto-matched from its assembly shape

struct T_func_00b11720 { void m(); };
extern T_func_00b11720 G1_func_00b11720;
void func_00b11720()
{
    G1_func_00b11720.m();
}
