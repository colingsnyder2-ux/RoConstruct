// roc 2012-06 00b11780  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11780
//
// 00b11780  b9d47ce100           mov ecx, 0xe17cd4
// 00b11785  e926f08fff           jmp 0x4107b0
// auto-matched from its assembly shape

struct T_func_00b11780 { void m(); };
extern T_func_00b11780 G1_func_00b11780;
void func_00b11780()
{
    G1_func_00b11780.m();
}
