// roc 2012-06 00b1aa40  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1aa40
//
// 00b1aa40  b9908de300           mov ecx, 0xe38d90
// 00b1aa45  e9b625c5ff           jmp 0x76d000
// auto-matched from its assembly shape

struct T_func_00b1aa40 { void m(); };
extern T_func_00b1aa40 G1_func_00b1aa40;
void func_00b1aa40()
{
    G1_func_00b1aa40.m();
}
