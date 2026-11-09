// roc 2012-06 00b12490  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12490
//
// 00b12490  b9c897e100           mov ecx, 0xe197c8
// 00b12495  e956faa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b12490 { void m(); };
extern T_func_00b12490 G1_func_00b12490;
void func_00b12490()
{
    G1_func_00b12490.m();
}
