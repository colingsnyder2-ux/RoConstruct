// roc 2012-06 00b11740  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11740
//
// 00b11740  b9c47ce100           mov ecx, 0xe17cc4
// 00b11745  e9960090ff           jmp 0x4117e0
// auto-matched from its assembly shape

struct T_func_00b11740 { void m(); };
extern T_func_00b11740 G1_func_00b11740;
void func_00b11740()
{
    G1_func_00b11740.m();
}
