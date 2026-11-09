// roc 2012-06 00b1ed50  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ed50
//
// 00b1ed50  b9f818e500           mov ecx, 0xe518f8
// 00b1ed55  e9e60cd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1ed50 { void m(); };
extern T_func_00b1ed50 G1_func_00b1ed50;
void func_00b1ed50()
{
    G1_func_00b1ed50.m();
}
