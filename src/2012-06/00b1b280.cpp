// roc 2012-06 00b1b280  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b280
//
// 00b1b280  b9a8b7e300           mov ecx, 0xe3b7a8
// 00b1b285  e9e6468fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b280 { void m(); };
extern T_func_00b1b280 G1_func_00b1b280;
void func_00b1b280()
{
    G1_func_00b1b280.m();
}
