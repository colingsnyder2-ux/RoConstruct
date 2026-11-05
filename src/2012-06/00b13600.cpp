// roc 2012-06 00b13600  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13600
//
// 00b13600  b9080be200           mov ecx, 0xe20b08
// 00b13605  e9e669b9ff           jmp 0x6a9ff0
// auto-matched from its assembly shape

struct T_func_00b13600 { void m(); };
extern T_func_00b13600 G1_func_00b13600;
void func_00b13600()
{
    G1_func_00b13600.m();
}
