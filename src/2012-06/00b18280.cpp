// roc 2012-06 00b18280  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18280
//
// 00b18280  b92456e300           mov ecx, 0xe35624
// 00b18285  e9769dd9ff           jmp 0x8b2000
// auto-matched from its assembly shape

struct T_func_00b18280 { void m(); };
extern T_func_00b18280 G1_func_00b18280;
void func_00b18280()
{
    G1_func_00b18280.m();
}
