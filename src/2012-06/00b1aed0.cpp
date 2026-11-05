// roc 2012-06 00b1aed0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1aed0
//
// 00b1aed0  b92028e400           mov ecx, 0xe42820
// 00b1aed5  e9964a8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1aed0 { void m(); };
extern T_func_00b1aed0 G1_func_00b1aed0;
void func_00b1aed0()
{
    G1_func_00b1aed0.m();
}
