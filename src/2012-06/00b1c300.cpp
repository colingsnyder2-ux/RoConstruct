// roc 2012-06 00b1c300  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c300
//
// 00b1c300  b930ade400           mov ecx, 0xe4ad30
// 00b1c305  e9e65ba7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1c300 { void m(); };
extern T_func_00b1c300 G1_func_00b1c300;
void func_00b1c300()
{
    G1_func_00b1c300.m();
}
