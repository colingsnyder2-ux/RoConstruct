// roc 2012-06 00b1dcf0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1dcf0
//
// 00b1dcf0  b950f5e400           mov ecx, 0xe4f550
// 00b1dcf5  e9461dd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1dcf0 { void m(); };
extern T_func_00b1dcf0 G1_func_00b1dcf0;
void func_00b1dcf0()
{
    G1_func_00b1dcf0.m();
}
