// roc 2012-06 00b129f0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b129f0
//
// 00b129f0  b99cc2e100           mov ecx, 0xe1c29c
// 00b129f5  e9f6af9aff           jmp 0x4bd9f0
// auto-matched from its assembly shape

struct T_func_00b129f0 { void m(); };
extern T_func_00b129f0 G1_func_00b129f0;
void func_00b129f0()
{
    G1_func_00b129f0.m();
}
