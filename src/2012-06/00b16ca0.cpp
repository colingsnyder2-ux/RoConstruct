// roc 2012-06 00b16ca0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16ca0
//
// 00b16ca0  b9e8fae200           mov ecx, 0xe2fae8
// 00b16ca5  e9962cbcff           jmp 0x6d9940
// auto-matched from its assembly shape

struct T_func_00b16ca0 { void m(); };
extern T_func_00b16ca0 G1_func_00b16ca0;
void func_00b16ca0()
{
    G1_func_00b16ca0.m();
}
