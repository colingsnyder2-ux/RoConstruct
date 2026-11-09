// roc 2012-06 00b1b520  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b520
//
// 00b1b520  b96c89e400           mov ecx, 0xe4896c
// 00b1b525  e946adc5ff           jmp 0x776270
// auto-matched from its assembly shape

struct T_func_00b1b520 { void m(); };
extern T_func_00b1b520 G1_func_00b1b520;
void func_00b1b520()
{
    G1_func_00b1b520.m();
}
