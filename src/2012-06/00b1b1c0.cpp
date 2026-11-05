// roc 2012-06 00b1b1c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b1c0
//
// 00b1b1c0  b988cee300           mov ecx, 0xe3ce88
// 00b1b1c5  e9a6478fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b1c0 { void m(); };
extern T_func_00b1b1c0 G1_func_00b1b1c0;
void func_00b1b1c0()
{
    G1_func_00b1b1c0.m();
}
