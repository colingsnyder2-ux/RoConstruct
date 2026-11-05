// roc 2012-06 00b1d550  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d550
//
// 00b1d550  b944e1e400           mov ecx, 0xe4e144
// 00b1d555  e99649a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1d550 { void m(); };
extern T_func_00b1d550 G1_func_00b1d550;
void func_00b1d550()
{
    G1_func_00b1d550.m();
}
