// roc 2012-06 00b1b230  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b230
//
// 00b1b230  b930c1e300           mov ecx, 0xe3c130
// 00b1b235  e936478fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b230 { void m(); };
extern T_func_00b1b230 G1_func_00b1b230;
void func_00b1b230()
{
    G1_func_00b1b230.m();
}
