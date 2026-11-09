// roc 2012-06 00b1bca0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1bca0
//
// 00b1bca0  b950a2e400           mov ecx, 0xe4a250
// 00b1bca5  e94662a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1bca0 { void m(); };
extern T_func_00b1bca0 G1_func_00b1bca0;
void func_00b1bca0()
{
    G1_func_00b1bca0.m();
}
