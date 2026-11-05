// roc 2012-06 00b16ee0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16ee0
//
// 00b16ee0  b988efe200           mov ecx, 0xe2ef88
// 00b16ee5  e906b0a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b16ee0 { void m(); };
extern T_func_00b16ee0 G1_func_00b16ee0;
void func_00b16ee0()
{
    G1_func_00b16ee0.m();
}
