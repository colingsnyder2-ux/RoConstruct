// roc 2012-06 00b14b40  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14b40
//
// 00b14b40  b9a07de200           mov ecx, 0xe27da0
// 00b14b45  e9b6f3abff           jmp 0x5d3f00
// auto-matched from its assembly shape

struct T_func_00b14b40 { void m(); };
extern T_func_00b14b40 G1_func_00b14b40;
void func_00b14b40()
{
    G1_func_00b14b40.m();
}
