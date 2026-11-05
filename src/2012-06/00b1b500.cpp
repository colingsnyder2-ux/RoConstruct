// roc 2012-06 00b1b500  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b500
//
// 00b1b500  b97c88e400           mov ecx, 0xe4887c
// 00b1b505  e906b7c5ff           jmp 0x776c10
// auto-matched from its assembly shape

struct T_func_00b1b500 { void m(); };
extern T_func_00b1b500 G1_func_00b1b500;
void func_00b1b500()
{
    G1_func_00b1b500.m();
}
