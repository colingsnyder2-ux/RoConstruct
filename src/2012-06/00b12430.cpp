// roc 2012-06 00b12430  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12430
//
// 00b12430  b9d090e100           mov ecx, 0xe190d0
// 00b12435  e9663e95ff           jmp 0x4662a0
// auto-matched from its assembly shape

struct T_func_00b12430 { void m(); };
extern T_func_00b12430 G1_func_00b12430;
void func_00b12430()
{
    G1_func_00b12430.m();
}
