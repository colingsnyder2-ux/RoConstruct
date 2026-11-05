// roc 2012-06 00b1f2c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f2c0
//
// 00b1f2c0  b9581ee500           mov ecx, 0xe51e58
// 00b1f2c5  e9d660d6ff           jmp 0x8853a0
// auto-matched from its assembly shape

struct T_func_00b1f2c0 { void m(); };
extern T_func_00b1f2c0 G1_func_00b1f2c0;
void func_00b1f2c0()
{
    G1_func_00b1f2c0.m();
}
