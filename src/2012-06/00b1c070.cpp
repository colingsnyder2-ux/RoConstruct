// roc 2012-06 00b1c070  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c070
//
// 00b1c070  b9a8a7e400           mov ecx, 0xe4a7a8
// 00b1c075  e9f650b6ff           jmp 0x681170
// auto-matched from its assembly shape

struct T_func_00b1c070 { void m(); };
extern T_func_00b1c070 G1_func_00b1c070;
void func_00b1c070()
{
    G1_func_00b1c070.m();
}
