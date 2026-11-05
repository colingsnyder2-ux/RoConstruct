// roc 2012-06 00b149d0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b149d0
//
// 00b149d0  b9685be200           mov ecx, 0xe25b68
// 00b149d5  e986b390ff           jmp 0x41fd60
// auto-matched from its assembly shape

struct T_func_00b149d0 { void m(); };
extern T_func_00b149d0 G1_func_00b149d0;
void func_00b149d0()
{
    G1_func_00b149d0.m();
}
