// roc 2012-06 00b187c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b187c0
//
// 00b187c0  b94864e300           mov ecx, 0xe36448
// 00b187c5  e916cfbaff           jmp 0x6c56e0
// auto-matched from its assembly shape

struct T_func_00b187c0 { void m(); };
extern T_func_00b187c0 G1_func_00b187c0;
void func_00b187c0()
{
    G1_func_00b187c0.m();
}
