// roc 2012-06 00b15fb0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15fb0
//
// 00b15fb0  b920cbe200           mov ecx, 0xe2cb20
// 00b15fb5  e9b6998fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b15fb0 { void m(); };
extern T_func_00b15fb0 G1_func_00b15fb0;
void func_00b15fb0()
{
    G1_func_00b15fb0.m();
}
