// roc 2012-06 00b1b200  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b200
//
// 00b1b200  b9e8c6e300           mov ecx, 0xe3c6e8
// 00b1b205  e966478fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b200 { void m(); };
extern T_func_00b1b200 G1_func_00b1b200;
void func_00b1b200()
{
    G1_func_00b1b200.m();
}
