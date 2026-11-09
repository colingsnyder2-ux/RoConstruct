// roc 2012-06 00b180b0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b180b0
//
// 00b180b0  b97843e300           mov ecx, 0xe34378
// 00b180b5  e9c6f0c1ff           jmp 0x737180
// auto-matched from its assembly shape

struct T_func_00b180b0 { void m(); };
extern T_func_00b180b0 G1_func_00b180b0;
void func_00b180b0()
{
    G1_func_00b180b0.m();
}
