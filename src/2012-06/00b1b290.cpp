// roc 2012-06 00b1b290  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b290
//
// 00b1b290  b9c0b5e300           mov ecx, 0xe3b5c0
// 00b1b295  e9d6468fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b290 { void m(); };
extern T_func_00b1b290 G1_func_00b1b290;
void func_00b1b290()
{
    G1_func_00b1b290.m();
}
