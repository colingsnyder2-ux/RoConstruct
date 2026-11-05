// roc 2012-06 00b15cf0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15cf0
//
// 00b15cf0  b9c8b3e200           mov ecx, 0xe2b3c8
// 00b15cf5  e9f6c1a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b15cf0 { void m(); };
extern T_func_00b15cf0 G1_func_00b15cf0;
void func_00b15cf0()
{
    G1_func_00b15cf0.m();
}
