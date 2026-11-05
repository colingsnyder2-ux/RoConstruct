// roc 2012-06 00b1b010  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b010
//
// 00b1b010  b90002e400           mov ecx, 0xe40200
// 00b1b015  e956498fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b010 { void m(); };
extern T_func_00b1b010 G1_func_00b1b010;
void func_00b1b010()
{
    G1_func_00b1b010.m();
}
