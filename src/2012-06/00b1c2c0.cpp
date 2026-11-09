// roc 2012-06 00b1c2c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c2c0
//
// 00b1c2c0  b9c8ace400           mov ecx, 0xe4acc8
// 00b1c2c5  e9265ca7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1c2c0 { void m(); };
extern T_func_00b1c2c0 G1_func_00b1c2c0;
void func_00b1c2c0()
{
    G1_func_00b1c2c0.m();
}
