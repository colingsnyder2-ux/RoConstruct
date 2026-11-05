// roc 2012-06 00b155e0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b155e0
//
// 00b155e0  b9888de200           mov ecx, 0xe28d88
// 00b155e5  e9c64db6ff           jmp 0x67a3b0
// auto-matched from its assembly shape

struct T_func_00b155e0 { void m(); };
extern T_func_00b155e0 G1_func_00b155e0;
void func_00b155e0()
{
    G1_func_00b155e0.m();
}
