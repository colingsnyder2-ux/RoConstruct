// roc 2012-06 00b1aaa0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1aaa0
//
// 00b1aaa0  b97089e300           mov ecx, 0xe38970
// 00b1aaa5  e99615c5ff           jmp 0x76c040
// auto-matched from its assembly shape

struct T_func_00b1aaa0 { void m(); };
extern T_func_00b1aaa0 G1_func_00b1aaa0;
void func_00b1aaa0()
{
    G1_func_00b1aaa0.m();
}
