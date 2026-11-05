// roc 2012-06 00b164c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b164c0
//
// 00b164c0  b9ade1e200           mov ecx, 0xe2e1ad
// 00b164c5  e9b63dbaff           jmp 0x6ba280
// auto-matched from its assembly shape

struct T_func_00b164c0 { void m(); };
extern T_func_00b164c0 G1_func_00b164c0;
void func_00b164c0()
{
    G1_func_00b164c0.m();
}
