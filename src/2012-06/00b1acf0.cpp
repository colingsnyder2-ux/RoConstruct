// roc 2012-06 00b1acf0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1acf0
//
// 00b1acf0  b95061e400           mov ecx, 0xe46150
// 00b1acf5  e9764c8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1acf0 { void m(); };
extern T_func_00b1acf0 G1_func_00b1acf0;
void func_00b1acf0()
{
    G1_func_00b1acf0.m();
}
