// roc 2012-06 00b1af90  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1af90
//
// 00b1af90  b94011e400           mov ecx, 0xe41140
// 00b1af95  e9d6498fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1af90 { void m(); };
extern T_func_00b1af90 G1_func_00b1af90;
void func_00b1af90()
{
    G1_func_00b1af90.m();
}
