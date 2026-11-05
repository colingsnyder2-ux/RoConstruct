// roc 2012-06 00b14c40  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14c40
//
// 00b14c40  b93887e200           mov ecx, 0xe28738
// 00b14c45  e976dcb1ff           jmp 0x6328c0
// auto-matched from its assembly shape

struct T_func_00b14c40 { void m(); };
extern T_func_00b14c40 G1_func_00b14c40;
void func_00b14c40()
{
    G1_func_00b14c40.m();
}
