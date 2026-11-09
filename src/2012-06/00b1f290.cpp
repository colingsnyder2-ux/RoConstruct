// roc 2012-06 00b1f290  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f290
//
// 00b1f290  b97021e500           mov ecx, 0xe52170
// 00b1f295  e9a607d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1f290 { void m(); };
extern T_func_00b1f290 G1_func_00b1f290;
void func_00b1f290()
{
    G1_func_00b1f290.m();
}
