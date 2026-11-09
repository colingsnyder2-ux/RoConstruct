// roc 2012-06 00b1a9e0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1a9e0
//
// 00b1a9e0  b9b091e300           mov ecx, 0xe391b0
// 00b1a9e5  e9b6a3c3ff           jmp 0x754da0
// auto-matched from its assembly shape

struct T_func_00b1a9e0 { void m(); };
extern T_func_00b1a9e0 G1_func_00b1a9e0;
void func_00b1a9e0()
{
    G1_func_00b1a9e0.m();
}
