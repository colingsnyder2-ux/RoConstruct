// roc 2012-06 00b1d430  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d430
//
// 00b1d430  b9e4e0e400           mov ecx, 0xe4e0e4
// 00b1d435  e9b64aa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1d430 { void m(); };
extern T_func_00b1d430 G1_func_00b1d430;
void func_00b1d430()
{
    G1_func_00b1d430.m();
}
