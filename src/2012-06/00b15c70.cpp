// roc 2012-06 00b15c70  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15c70
//
// 00b15c70  b988b2e200           mov ecx, 0xe2b288
// 00b15c75  e976c2a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b15c70 { void m(); };
extern T_func_00b15c70 G1_func_00b15c70;
void func_00b15c70()
{
    G1_func_00b15c70.m();
}
