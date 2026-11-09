// roc 2012-06 00b202d0  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b202d0
//
// 00b202d0  b95849e500           mov ecx, 0xe54958
// 00b202d5  e9161ca7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b202d0 { void m(); };
extern T_func_00b202d0 G1_func_00b202d0;
void func_00b202d0()
{
    G1_func_00b202d0.m();
}
