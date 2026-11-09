// roc 2012-06 00b155f0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b155f0
//
// 00b155f0  b9b08ce200           mov ecx, 0xe28cb0
// 00b155f5  e9b65cb6ff           jmp 0x67b2b0
// auto-matched from its assembly shape

struct T_func_00b155f0 { void m(); };
extern T_func_00b155f0 G1_func_00b155f0;
void func_00b155f0()
{
    G1_func_00b155f0.m();
}
