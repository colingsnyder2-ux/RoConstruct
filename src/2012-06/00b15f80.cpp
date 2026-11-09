// roc 2012-06 00b15f80  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15f80
//
// 00b15f80  b988c8e200           mov ecx, 0xe2c888
// 00b15f85  e9c6ebb7ff           jmp 0x694b50
// auto-matched from its assembly shape

struct T_func_00b15f80 { void m(); };
extern T_func_00b15f80 G1_func_00b15f80;
void func_00b15f80()
{
    G1_func_00b15f80.m();
}
