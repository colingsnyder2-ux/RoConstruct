// roc 2012-06 00b21830  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b21830
//
// 00b21830  b9fca3e500           mov ecx, 0xe5a3fc
// 00b21835  e9127ff7ff           jmp 0xa9974c
// auto-matched from its assembly shape

struct T_func_00b21830 { void m(); };
extern T_func_00b21830 G1_func_00b21830;
void func_00b21830()
{
    G1_func_00b21830.m();
}
