// roc 2012-06 00b1b3a0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b3a0
//
// 00b1b3a0  b9f88ae400           mov ecx, 0xe48af8
// 00b1b3a5  e9362ec6ff           jmp 0x77e1e0
// auto-matched from its assembly shape

struct T_func_00b1b3a0 { void m(); };
extern T_func_00b1b3a0 G1_func_00b1b3a0;
void func_00b1b3a0()
{
    G1_func_00b1b3a0.m();
}
