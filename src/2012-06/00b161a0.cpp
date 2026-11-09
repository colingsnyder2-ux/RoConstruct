// roc 2012-06 00b161a0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b161a0
//
// 00b161a0  b968d3e200           mov ecx, 0xe2d368
// 00b161a5  e9c6978fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b161a0 { void m(); };
extern T_func_00b161a0 G1_func_00b161a0;
void func_00b161a0()
{
    G1_func_00b161a0.m();
}
