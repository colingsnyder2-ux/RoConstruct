// roc 2012-06 00b1aae0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1aae0
//
// 00b1aae0  b9b086e300           mov ecx, 0xe386b0
// 00b1aae5  e9060dc5ff           jmp 0x76b7f0
// auto-matched from its assembly shape

struct T_func_00b1aae0 { void m(); };
extern T_func_00b1aae0 G1_func_00b1aae0;
void func_00b1aae0()
{
    G1_func_00b1aae0.m();
}
