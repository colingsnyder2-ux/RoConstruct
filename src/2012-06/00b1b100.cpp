// roc 2012-06 00b1b100  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b100
//
// 00b1b100  b968e5e300           mov ecx, 0xe3e568
// 00b1b105  e966488fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b100 { void m(); };
extern T_func_00b1b100 G1_func_00b1b100;
void func_00b1b100()
{
    G1_func_00b1b100.m();
}
