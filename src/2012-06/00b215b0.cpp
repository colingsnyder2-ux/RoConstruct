// roc 2012-06 00b215b0  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b215b0
//
// 00b215b0  b93c94e500           mov ecx, 0xe5943c
// 00b215b5  e9869ce8ff           jmp 0x9ab240
// auto-matched from its assembly shape

struct T_func_00b215b0 { void m(); };
extern T_func_00b215b0 G1_func_00b215b0;
void func_00b215b0()
{
    G1_func_00b215b0.m();
}
