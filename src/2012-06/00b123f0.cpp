// roc 2012-06 00b123f0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b123f0
//
// 00b123f0  b99093e100           mov ecx, 0xe19390
// 00b123f5  e9e64795ff           jmp 0x466be0
// auto-matched from its assembly shape

struct T_func_00b123f0 { void m(); };
extern T_func_00b123f0 G1_func_00b123f0;
void func_00b123f0()
{
    G1_func_00b123f0.m();
}
