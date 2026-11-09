// roc 2012-06 00b1eda0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1eda0
//
// 00b1eda0  b9c019e500           mov ecx, 0xe519c0
// 00b1eda5  e9960cd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1eda0 { void m(); };
extern T_func_00b1eda0 G1_func_00b1eda0;
void func_00b1eda0()
{
    G1_func_00b1eda0.m();
}
