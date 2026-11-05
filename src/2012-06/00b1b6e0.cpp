// roc 2012-06 00b1b6e0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b6e0
//
// 00b1b6e0  b9a88ee400           mov ecx, 0xe48ea8
// 00b1b6e5  e96642bcff           jmp 0x6df950
// auto-matched from its assembly shape

struct T_func_00b1b6e0 { void m(); };
extern T_func_00b1b6e0 G1_func_00b1b6e0;
void func_00b1b6e0()
{
    G1_func_00b1b6e0.m();
}
