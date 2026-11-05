// roc 2012-06 00b1ae50  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ae50
//
// 00b1ae50  b96037e400           mov ecx, 0xe43760
// 00b1ae55  e9164b8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1ae50 { void m(); };
extern T_func_00b1ae50 G1_func_00b1ae50;
void func_00b1ae50()
{
    G1_func_00b1ae50.m();
}
