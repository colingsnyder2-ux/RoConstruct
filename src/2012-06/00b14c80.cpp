// roc 2012-06 00b14c80  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14c80
//
// 00b14c80  b98c87e200           mov ecx, 0xe2878c
// 00b14c85  e90683d0ff           jmp 0x81cf90
// auto-matched from its assembly shape

struct T_func_00b14c80 { void m(); };
extern T_func_00b14c80 G1_func_00b14c80;
void func_00b14c80()
{
    G1_func_00b14c80.m();
}
