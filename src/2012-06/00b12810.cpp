// roc 2012-06 00b12810  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12810
//
// 00b12810  b938a9e100           mov ecx, 0xe1a938
// 00b12815  e9966098ff           jmp 0x4988b0
// auto-matched from its assembly shape

struct T_func_00b12810 { void m(); };
extern T_func_00b12810 G1_func_00b12810;
void func_00b12810()
{
    G1_func_00b12810.m();
}
