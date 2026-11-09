// roc 2012-06 00b1aa50  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1aa50
//
// 00b1aa50  b9e08ce300           mov ecx, 0xe38ce0
// 00b1aa55  e90623c5ff           jmp 0x76cd60
// auto-matched from its assembly shape

struct T_func_00b1aa50 { void m(); };
extern T_func_00b1aa50 G1_func_00b1aa50;
void func_00b1aa50()
{
    G1_func_00b1aa50.m();
}
