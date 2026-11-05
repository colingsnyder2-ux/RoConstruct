// roc 2012-06 00b17870  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17870
//
// 00b17870  b9d821e300           mov ecx, 0xe321d8
// 00b17875  e9d6f1c7ff           jmp 0x796a50
// auto-matched from its assembly shape

struct T_func_00b17870 { void m(); };
extern T_func_00b17870 G1_func_00b17870;
void func_00b17870()
{
    G1_func_00b17870.m();
}
