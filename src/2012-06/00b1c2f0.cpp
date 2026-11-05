// roc 2012-06 00b1c2f0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c2f0
//
// 00b1c2f0  b990ace400           mov ecx, 0xe4ac90
// 00b1c2f5  e9f65ba7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1c2f0 { void m(); };
extern T_func_00b1c2f0 G1_func_00b1c2f0;
void func_00b1c2f0()
{
    G1_func_00b1c2f0.m();
}
