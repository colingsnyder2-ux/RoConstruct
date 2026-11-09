// roc 2012-06 00b1af50  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1af50
//
// 00b1af50  b9e018e400           mov ecx, 0xe418e0
// 00b1af55  e9164a8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1af50 { void m(); };
extern T_func_00b1af50 G1_func_00b1af50;
void func_00b1af50()
{
    G1_func_00b1af50.m();
}
