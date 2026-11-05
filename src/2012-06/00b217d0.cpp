// roc 2012-06 00b217d0  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b217d0
//
// 00b217d0  b99ca0e500           mov ecx, 0xe5a09c
// 00b217d5  e9e884f7ff           jmp 0xa99cc2
// auto-matched from its assembly shape

struct T_func_00b217d0 { void m(); };
extern T_func_00b217d0 G1_func_00b217d0;
void func_00b217d0()
{
    G1_func_00b217d0.m();
}
