// roc 2012-06 00b20be0  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20be0
//
// 00b20be0  b9a85ee500           mov ecx, 0xe55ea8
// 00b20be5  e98605b6ff           jmp 0x681170
// auto-matched from its assembly shape

struct T_func_00b20be0 { void m(); };
extern T_func_00b20be0 G1_func_00b20be0;
void func_00b20be0()
{
    G1_func_00b20be0.m();
}
