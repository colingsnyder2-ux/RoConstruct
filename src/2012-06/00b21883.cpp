// roc 2012-06 00b21883  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b21883
//
// 00b21883  b918a5e500           mov ecx, 0xe5a518
// 00b21888  e98fa6f5ff           jmp 0xa7bf1c
// auto-matched from its assembly shape

struct T_func_00b21883 { void m(); };
extern T_func_00b21883 G1_func_00b21883;
void func_00b21883()
{
    G1_func_00b21883.m();
}
