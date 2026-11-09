// roc 2012-06 00b1d400  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d400
//
// 00b1d400  b9a4e1e400           mov ecx, 0xe4e1a4
// 00b1d405  e9e64aa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1d400 { void m(); };
extern T_func_00b1d400 G1_func_00b1d400;
void func_00b1d400()
{
    G1_func_00b1d400.m();
}
