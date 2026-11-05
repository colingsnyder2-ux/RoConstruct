// roc 2012-06 00b135a0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b135a0
//
// 00b135a0  b9f014e200           mov ecx, 0xe214f0
// 00b135a5  e98625a1ff           jmp 0x525b30
// auto-matched from its assembly shape

struct T_func_00b135a0 { void m(); };
extern T_func_00b135a0 G1_func_00b135a0;
void func_00b135a0()
{
    G1_func_00b135a0.m();
}
