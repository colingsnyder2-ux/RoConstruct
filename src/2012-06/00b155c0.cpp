// roc 2012-06 00b155c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b155c0
//
// 00b155c0  b9e88ee200           mov ecx, 0xe28ee8
// 00b155c5  e98652b6ff           jmp 0x67a850
// auto-matched from its assembly shape

struct T_func_00b155c0 { void m(); };
extern T_func_00b155c0 G1_func_00b155c0;
void func_00b155c0()
{
    G1_func_00b155c0.m();
}
