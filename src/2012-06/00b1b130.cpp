// roc 2012-06 00b1b130  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b130
//
// 00b1b130  b9b0dfe300           mov ecx, 0xe3dfb0
// 00b1b135  e936488fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b130 { void m(); };
extern T_func_00b1b130 G1_func_00b1b130;
void func_00b1b130()
{
    G1_func_00b1b130.m();
}
