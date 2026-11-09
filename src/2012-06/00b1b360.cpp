// roc 2012-06 00b1b360  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b360
//
// 00b1b360  b9f89ce300           mov ecx, 0xe39cf8
// 00b1b365  e906468fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b360 { void m(); };
extern T_func_00b1b360 G1_func_00b1b360;
void func_00b1b360()
{
    G1_func_00b1b360.m();
}
