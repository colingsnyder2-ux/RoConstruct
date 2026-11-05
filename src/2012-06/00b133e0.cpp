// roc 2012-06 00b133e0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b133e0
//
// 00b133e0  b97006e200           mov ecx, 0xe20670
// 00b133e5  e956c6d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b133e0 { void m(); };
extern T_func_00b133e0 G1_func_00b133e0;
void func_00b133e0()
{
    G1_func_00b133e0.m();
}
