// roc 2012-06 00b1d460  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d460
//
// 00b1d460  b914e1e400           mov ecx, 0xe4e114
// 00b1d465  e9864aa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1d460 { void m(); };
extern T_func_00b1d460 G1_func_00b1d460;
void func_00b1d460()
{
    G1_func_00b1d460.m();
}
