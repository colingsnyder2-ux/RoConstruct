// roc 2012-06 00b1a9c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1a9c0
//
// 00b1a9c0  b91093e300           mov ecx, 0xe39310
// 00b1a9c5  e90638c5ff           jmp 0x76e1d0
// auto-matched from its assembly shape

struct T_func_00b1a9c0 { void m(); };
extern T_func_00b1a9c0 G1_func_00b1a9c0;
void func_00b1a9c0()
{
    G1_func_00b1a9c0.m();
}
