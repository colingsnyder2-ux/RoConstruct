// roc 2012-06 00b163a0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b163a0
//
// 00b163a0  b990d7e200           mov ecx, 0xe2d790
// 00b163a5  e9763db9ff           jmp 0x6aa120
// auto-matched from its assembly shape

struct T_func_00b163a0 { void m(); };
extern T_func_00b163a0 G1_func_00b163a0;
void func_00b163a0()
{
    G1_func_00b163a0.m();
}
