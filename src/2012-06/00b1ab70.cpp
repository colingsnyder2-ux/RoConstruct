// roc 2012-06 00b1ab70  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ab70
//
// 00b1ab70  b98080e300           mov ecx, 0xe38080
// 00b1ab75  e976f7c4ff           jmp 0x76a2f0
// auto-matched from its assembly shape

struct T_func_00b1ab70 { void m(); };
extern T_func_00b1ab70 G1_func_00b1ab70;
void func_00b1ab70()
{
    G1_func_00b1ab70.m();
}
