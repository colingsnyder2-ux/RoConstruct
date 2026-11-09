// roc 2012-06 00b1aa80  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1aa80
//
// 00b1aa80  b9d08ae300           mov ecx, 0xe38ad0
// 00b1aa85  e9f61ac5ff           jmp 0x76c580
// auto-matched from its assembly shape

struct T_func_00b1aa80 { void m(); };
extern T_func_00b1aa80 G1_func_00b1aa80;
void func_00b1aa80()
{
    G1_func_00b1aa80.m();
}
