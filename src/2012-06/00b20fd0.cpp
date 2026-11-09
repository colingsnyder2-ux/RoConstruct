// roc 2012-06 00b20fd0  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20fd0
//
// 00b20fd0  b9ec66e500           mov ecx, 0xe566ec
// 00b20fd5  e9160fa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b20fd0 { void m(); };
extern T_func_00b20fd0 G1_func_00b20fd0;
void func_00b20fd0()
{
    G1_func_00b20fd0.m();
}
