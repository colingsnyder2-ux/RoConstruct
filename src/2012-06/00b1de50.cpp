// roc 2012-06 00b1de50  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1de50
//
// 00b1de50  b980fbe400           mov ecx, 0xe4fb80
// 00b1de55  e99640a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1de50 { void m(); };
extern T_func_00b1de50 G1_func_00b1de50;
void func_00b1de50()
{
    G1_func_00b1de50.m();
}
