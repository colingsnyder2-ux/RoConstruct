// roc 2012-06 00b1b020  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b020
//
// 00b1b020  b91800e400           mov ecx, 0xe40018
// 00b1b025  e946498fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b020 { void m(); };
extern T_func_00b1b020 G1_func_00b1b020;
void func_00b1b020()
{
    G1_func_00b1b020.m();
}
