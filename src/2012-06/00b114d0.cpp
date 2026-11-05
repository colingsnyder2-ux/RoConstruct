// roc 2012-06 00b114d0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b114d0
//
// 00b114d0  b9a864e100           mov ecx, 0xe164a8
// 00b114d5  e976928fff           jmp 0x40a750
// auto-matched from its assembly shape

struct T_func_00b114d0 { void m(); };
extern T_func_00b114d0 G1_func_00b114d0;
void func_00b114d0()
{
    G1_func_00b114d0.m();
}
