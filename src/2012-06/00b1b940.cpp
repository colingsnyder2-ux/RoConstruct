// roc 2012-06 00b1b940  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b940
//
// 00b1b940  b94895e400           mov ecx, 0xe49548
// 00b1b945  e9f640d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1b940 { void m(); };
extern T_func_00b1b940 G1_func_00b1b940;
void func_00b1b940()
{
    G1_func_00b1b940.m();
}
