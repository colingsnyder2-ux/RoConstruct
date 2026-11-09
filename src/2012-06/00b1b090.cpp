// roc 2012-06 00b1b090  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b090
//
// 00b1b090  b9c0f2e300           mov ecx, 0xe3f2c0
// 00b1b095  e9d6488fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b090 { void m(); };
extern T_func_00b1b090 G1_func_00b1b090;
void func_00b1b090()
{
    G1_func_00b1b090.m();
}
