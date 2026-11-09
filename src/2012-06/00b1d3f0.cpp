// roc 2012-06 00b1d3f0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d3f0
//
// 00b1d3f0  b9f0dfe400           mov ecx, 0xe4dff0
// 00b1d3f5  e9f64aa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1d3f0 { void m(); };
extern T_func_00b1d3f0 G1_func_00b1d3f0;
void func_00b1d3f0()
{
    G1_func_00b1d3f0.m();
}
