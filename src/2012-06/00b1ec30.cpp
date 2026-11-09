// roc 2012-06 00b1ec30  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ec30
//
// 00b1ec30  b9e814e500           mov ecx, 0xe514e8
// 00b1ec35  e9b632a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1ec30 { void m(); };
extern T_func_00b1ec30 G1_func_00b1ec30;
void func_00b1ec30()
{
    G1_func_00b1ec30.m();
}
