// roc 2012-06 00b1c0d0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c0d0
//
// 00b1c0d0  b918a8e400           mov ecx, 0xe4a818
// 00b1c0d5  e9165ea7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1c0d0 { void m(); };
extern T_func_00b1c0d0 G1_func_00b1c0d0;
void func_00b1c0d0()
{
    G1_func_00b1c0d0.m();
}
