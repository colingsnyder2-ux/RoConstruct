// roc 2012-06 00b20fe0  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20fe0
//
// 00b20fe0  b94067e500           mov ecx, 0xe56740
// 00b20fe5  e98601b6ff           jmp 0x681170
// auto-matched from its assembly shape

struct T_func_00b20fe0 { void m(); };
extern T_func_00b20fe0 G1_func_00b20fe0;
void func_00b20fe0()
{
    G1_func_00b20fe0.m();
}
