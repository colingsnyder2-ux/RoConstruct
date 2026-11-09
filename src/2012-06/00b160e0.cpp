// roc 2012-06 00b160e0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b160e0
//
// 00b160e0  b918cfe200           mov ecx, 0xe2cf18
// 00b160e5  e986988fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b160e0 { void m(); };
extern T_func_00b160e0 G1_func_00b160e0;
void func_00b160e0()
{
    G1_func_00b160e0.m();
}
