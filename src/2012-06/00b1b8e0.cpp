// roc 2012-06 00b1b8e0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b8e0
//
// 00b1b8e0  b9b092e400           mov ecx, 0xe492b0
// 00b1b8e5  e90666a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1b8e0 { void m(); };
extern T_func_00b1b8e0 G1_func_00b1b8e0;
void func_00b1b8e0()
{
    G1_func_00b1b8e0.m();
}
