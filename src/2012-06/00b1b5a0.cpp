// roc 2012-06 00b1b5a0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b5a0
//
// 00b1b5a0  b9dc8ae400           mov ecx, 0xe48adc
// 00b1b5a5  e94686c5ff           jmp 0x773bf0
// auto-matched from its assembly shape

struct T_func_00b1b5a0 { void m(); };
extern T_func_00b1b5a0 G1_func_00b1b5a0;
void func_00b1b5a0()
{
    G1_func_00b1b5a0.m();
}
