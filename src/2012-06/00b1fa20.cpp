// roc 2012-06 00b1fa20  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1fa20
//
// 00b1fa20  b95833e500           mov ecx, 0xe53358
// 00b1fa25  e9c624a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1fa20 { void m(); };
extern T_func_00b1fa20 G1_func_00b1fa20;
void func_00b1fa20()
{
    G1_func_00b1fa20.m();
}
