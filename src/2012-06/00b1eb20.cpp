// roc 2012-06 00b1eb20  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1eb20
//
// 00b1eb20  b98411e500           mov ecx, 0xe51184
// 00b1eb25  e9b63ca5ff           jmp 0x5727e0
// auto-matched from its assembly shape

struct T_func_00b1eb20 { void m(); };
extern T_func_00b1eb20 G1_func_00b1eb20;
void func_00b1eb20()
{
    G1_func_00b1eb20.m();
}
