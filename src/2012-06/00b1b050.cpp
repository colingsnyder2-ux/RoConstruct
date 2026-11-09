// roc 2012-06 00b1b050  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b050
//
// 00b1b050  b960fae300           mov ecx, 0xe3fa60
// 00b1b055  e916498fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b050 { void m(); };
extern T_func_00b1b050 G1_func_00b1b050;
void func_00b1b050()
{
    G1_func_00b1b050.m();
}
