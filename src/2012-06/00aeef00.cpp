// roc 2012-06 00aeef00  unit: seg_00ae0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00aeef00
//
// 00aeef00  b91837e200           mov ecx, 0xe23718
// 00aeef05  e9f66df0ff           jmp 0x9f5d00
// auto-matched from its assembly shape

struct T_func_00aeef00 { void m(); };
extern T_func_00aeef00 G1_func_00aeef00;
void func_00aeef00()
{
    G1_func_00aeef00.m();
}
