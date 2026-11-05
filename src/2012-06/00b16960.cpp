// roc 2012-06 00b16960  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16960
//
// 00b16960  b950e8e200           mov ecx, 0xe2e850
// 00b16965  e97649bbff           jmp 0x6cb2e0
// auto-matched from its assembly shape

struct T_func_00b16960 { void m(); };
extern T_func_00b16960 G1_func_00b16960;
void func_00b16960()
{
    G1_func_00b16960.m();
}
