// roc 2012-06 00b1d480  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d480
//
// 00b1d480  b954e2e400           mov ecx, 0xe4e254
// 00b1d485  e9664aa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1d480 { void m(); };
extern T_func_00b1d480 G1_func_00b1d480;
void func_00b1d480()
{
    G1_func_00b1d480.m();
}
