// roc 2012-06 00b13c00  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13c00
//
// 00b13c00  b9e825e200           mov ecx, 0xe225e8
// 00b13c05  e9c65da3ff           jmp 0x5499d0
// auto-matched from its assembly shape

struct T_func_00b13c00 { void m(); };
extern T_func_00b13c00 G1_func_00b13c00;
void func_00b13c00()
{
    G1_func_00b13c00.m();
}
