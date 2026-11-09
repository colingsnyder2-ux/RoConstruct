// roc 2012-06 00b12930  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12930
//
// 00b12930  b9a0c1e100           mov ecx, 0xe1c1a0
// 00b12935  e916fd99ff           jmp 0x4b2650
// auto-matched from its assembly shape

struct T_func_00b12930 { void m(); };
extern T_func_00b12930 G1_func_00b12930;
void func_00b12930()
{
    G1_func_00b12930.m();
}
