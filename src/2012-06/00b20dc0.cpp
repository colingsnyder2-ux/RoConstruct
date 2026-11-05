// roc 2012-06 00b20dc0  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20dc0
//
// 00b20dc0  b9e862e500           mov ecx, 0xe562e8
// 00b20dc5  e92611a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b20dc0 { void m(); };
extern T_func_00b20dc0 G1_func_00b20dc0;
void func_00b20dc0()
{
    G1_func_00b20dc0.m();
}
