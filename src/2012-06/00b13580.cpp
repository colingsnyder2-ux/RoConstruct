// roc 2012-06 00b13580  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13580
//
// 00b13580  b91015e200           mov ecx, 0xe21510
// 00b13585  e9c62da1ff           jmp 0x526350
// auto-matched from its assembly shape

struct T_func_00b13580 { void m(); };
extern T_func_00b13580 G1_func_00b13580;
void func_00b13580()
{
    G1_func_00b13580.m();
}
