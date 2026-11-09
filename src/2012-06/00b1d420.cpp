// roc 2012-06 00b1d420  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d420
//
// 00b1d420  b958e7e400           mov ecx, 0xe4e758
// 00b1d425  e9c64aa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1d420 { void m(); };
extern T_func_00b1d420 G1_func_00b1d420;
void func_00b1d420()
{
    G1_func_00b1d420.m();
}
