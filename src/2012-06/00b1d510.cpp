// roc 2012-06 00b1d510  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d510
//
// 00b1d510  b9a4e6e400           mov ecx, 0xe4e6a4
// 00b1d515  e9d649a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1d510 { void m(); };
extern T_func_00b1d510 G1_func_00b1d510;
void func_00b1d510()
{
    G1_func_00b1d510.m();
}
