// roc 2012-06 00b1b1e0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b1e0
//
// 00b1b1e0  b9b8cae300           mov ecx, 0xe3cab8
// 00b1b1e5  e986478fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b1e0 { void m(); };
extern T_func_00b1b1e0 G1_func_00b1b1e0;
void func_00b1b1e0()
{
    G1_func_00b1b1e0.m();
}
