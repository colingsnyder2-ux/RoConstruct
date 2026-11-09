// roc 2012-06 00b1ecb0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ecb0
//
// 00b1ecb0  b9f815e500           mov ecx, 0xe515f8
// 00b1ecb5  e9860dd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1ecb0 { void m(); };
extern T_func_00b1ecb0 G1_func_00b1ecb0;
void func_00b1ecb0()
{
    G1_func_00b1ecb0.m();
}
