// roc 2012-06 00b207a0  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b207a0
//
// 00b207a0  b91858e500           mov ecx, 0xe55818
// 00b207a5  e94617a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b207a0 { void m(); };
extern T_func_00b207a0 G1_func_00b207a0;
void func_00b207a0()
{
    G1_func_00b207a0.m();
}
