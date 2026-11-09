// roc 2012-06 00aec8f0  unit: seg_00ae0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00aec8f0
//
// 00aec8f0  b9fc10e200           mov ecx, 0xe210fc
// 00aec8f5  e93651a7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00aec8f0 { void m(); };
extern T_func_00aec8f0 G1_func_00aec8f0;
void func_00aec8f0()
{
    G1_func_00aec8f0.m();
}
