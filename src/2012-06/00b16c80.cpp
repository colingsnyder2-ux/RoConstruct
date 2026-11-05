// roc 2012-06 00b16c80  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16c80
//
// 00b16c80  b948fce200           mov ecx, 0xe2fc48
// 00b16c85  e9c630bcff           jmp 0x6d9d50
// auto-matched from its assembly shape

struct T_func_00b16c80 { void m(); };
extern T_func_00b16c80 G1_func_00b16c80;
void func_00b16c80()
{
    G1_func_00b16c80.m();
}
