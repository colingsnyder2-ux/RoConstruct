// roc 2012-06 00b14880  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14880
//
// 00b14880  b9f84be200           mov ecx, 0xe24bf8
// 00b14885  e966d6a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b14880 { void m(); };
extern T_func_00b14880 G1_func_00b14880;
void func_00b14880()
{
    G1_func_00b14880.m();
}
