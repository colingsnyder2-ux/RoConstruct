// roc 2012-06 00b126a0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b126a0
//
// 00b126a0  b938a4e100           mov ecx, 0xe1a438
// 00b126a5  e9a62396ff           jmp 0x474a50
// auto-matched from its assembly shape

struct T_func_00b126a0 { void m(); };
extern T_func_00b126a0 G1_func_00b126a0;
void func_00b126a0()
{
    G1_func_00b126a0.m();
}
