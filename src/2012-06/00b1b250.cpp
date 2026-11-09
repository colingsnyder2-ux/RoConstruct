// roc 2012-06 00b1b250  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b250
//
// 00b1b250  b960bde300           mov ecx, 0xe3bd60
// 00b1b255  e916478fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b250 { void m(); };
extern T_func_00b1b250 G1_func_00b1b250;
void func_00b1b250()
{
    G1_func_00b1b250.m();
}
