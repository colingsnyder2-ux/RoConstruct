// roc 2012-06 00b20e80  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20e80
//
// 00b20e80  b91065e500           mov ecx, 0xe56510
// 00b20e85  e96610a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b20e80 { void m(); };
extern T_func_00b20e80 G1_func_00b20e80;
void func_00b20e80()
{
    G1_func_00b20e80.m();
}
