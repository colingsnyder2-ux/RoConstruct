// roc 2012-06 00b155b0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b155b0
//
// 00b155b0  b9988fe200           mov ecx, 0xe28f98
// 00b155b5  e9e654b6ff           jmp 0x67aaa0
// auto-matched from its assembly shape

struct T_func_00b155b0 { void m(); };
extern T_func_00b155b0 G1_func_00b155b0;
void func_00b155b0()
{
    G1_func_00b155b0.m();
}
