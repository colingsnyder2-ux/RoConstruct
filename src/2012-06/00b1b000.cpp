// roc 2012-06 00b1b000  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b000
//
// 00b1b000  b9e803e400           mov ecx, 0xe403e8
// 00b1b005  e966498fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b000 { void m(); };
extern T_func_00b1b000 G1_func_00b1b000;
void func_00b1b000()
{
    G1_func_00b1b000.m();
}
