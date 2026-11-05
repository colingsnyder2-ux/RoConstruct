// roc 2012-06 00b1e5e0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e5e0
//
// 00b1e5e0  b97807e500           mov ecx, 0xe50778
// 00b1e5e5  e9e693cfff           jmp 0x8179d0
// auto-matched from its assembly shape

struct T_func_00b1e5e0 { void m(); };
extern T_func_00b1e5e0 G1_func_00b1e5e0;
void func_00b1e5e0()
{
    G1_func_00b1e5e0.m();
}
