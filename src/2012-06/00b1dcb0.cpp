// roc 2012-06 00b1dcb0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1dcb0
//
// 00b1dcb0  b990f5e400           mov ecx, 0xe4f590
// 00b1dcb5  e9861dd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1dcb0 { void m(); };
extern T_func_00b1dcb0 G1_func_00b1dcb0;
void func_00b1dcb0()
{
    G1_func_00b1dcb0.m();
}
