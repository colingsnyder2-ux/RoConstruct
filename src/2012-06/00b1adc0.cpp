// roc 2012-06 00b1adc0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1adc0
//
// 00b1adc0  b98848e400           mov ecx, 0xe44888
// 00b1adc5  e9a64b8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1adc0 { void m(); };
extern T_func_00b1adc0 G1_func_00b1adc0;
void func_00b1adc0()
{
    G1_func_00b1adc0.m();
}
