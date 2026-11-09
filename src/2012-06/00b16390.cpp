// roc 2012-06 00b16390  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16390
//
// 00b16390  b918d9e200           mov ecx, 0xe2d918
// 00b16395  e956bba7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b16390 { void m(); };
extern T_func_00b16390 G1_func_00b16390;
void func_00b16390()
{
    G1_func_00b16390.m();
}
