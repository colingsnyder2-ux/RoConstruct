// roc 2012-06 00b1fac0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1fac0
//
// 00b1fac0  b9b835e500           mov ecx, 0xe535b8
// 00b1fac5  e92624a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1fac0 { void m(); };
extern T_func_00b1fac0 G1_func_00b1fac0;
void func_00b1fac0()
{
    G1_func_00b1fac0.m();
}
