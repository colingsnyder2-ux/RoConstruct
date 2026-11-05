// roc 2012-06 00b1c340  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c340
//
// 00b1c340  b968ade400           mov ecx, 0xe4ad68
// 00b1c345  e9a65ba7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1c340 { void m(); };
extern T_func_00b1c340 G1_func_00b1c340;
void func_00b1c340()
{
    G1_func_00b1c340.m();
}
