// roc 2012-06 00b12420  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12420
//
// 00b12420  b98091e100           mov ecx, 0xe19180
// 00b12425  e9f64095ff           jmp 0x466520
// auto-matched from its assembly shape

struct T_func_00b12420 { void m(); };
extern T_func_00b12420 G1_func_00b12420;
void func_00b12420()
{
    G1_func_00b12420.m();
}
