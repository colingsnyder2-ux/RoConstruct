// roc 2012-06 00b16c70  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16c70
//
// 00b16c70  b9fcf9e200           mov ecx, 0xe2f9fc
// 00b16c75  e996c3bbff           jmp 0x6d3010
// auto-matched from its assembly shape

struct T_func_00b16c70 { void m(); };
extern T_func_00b16c70 G1_func_00b16c70;
void func_00b16c70()
{
    G1_func_00b16c70.m();
}
