// roc 2012-06 00b207f0  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b207f0
//
// 00b207f0  b95058e500           mov ecx, 0xe55850
// 00b207f5  e9f616a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b207f0 { void m(); };
extern T_func_00b207f0 G1_func_00b207f0;
void func_00b207f0()
{
    G1_func_00b207f0.m();
}
