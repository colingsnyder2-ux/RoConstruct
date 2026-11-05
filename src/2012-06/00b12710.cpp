// roc 2012-06 00b12710  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12710
//
// 00b12710  b970a4e100           mov ecx, 0xe1a470
// 00b12715  e9766e96ff           jmp 0x479590
// auto-matched from its assembly shape

struct T_func_00b12710 { void m(); };
extern T_func_00b12710 G1_func_00b12710;
void func_00b12710()
{
    G1_func_00b12710.m();
}
