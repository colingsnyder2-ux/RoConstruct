// roc 2012-06 00b113f0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b113f0
//
// 00b113f0  b98c63e100           mov ecx, 0xe1638c
// 00b113f5  e956108fff           jmp 0x402450
// auto-matched from its assembly shape

struct T_func_00b113f0 { void m(); };
extern T_func_00b113f0 G1_func_00b113f0;
void func_00b113f0()
{
    G1_func_00b113f0.m();
}
