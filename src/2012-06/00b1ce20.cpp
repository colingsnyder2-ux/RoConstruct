// roc 2012-06 00b1ce20  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ce20
//
// 00b1ce20  b930d9e400           mov ecx, 0xe4d930
// 00b1ce25  e9162cd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1ce20 { void m(); };
extern T_func_00b1ce20 G1_func_00b1ce20;
void func_00b1ce20()
{
    G1_func_00b1ce20.m();
}
