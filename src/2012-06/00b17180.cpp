// roc 2012-06 00b17180  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17180
//
// 00b17180  b90805e300           mov ecx, 0xe30508
// 00b17185  e9e6878fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b17180 { void m(); };
extern T_func_00b17180 G1_func_00b17180;
void func_00b17180()
{
    G1_func_00b17180.m();
}
