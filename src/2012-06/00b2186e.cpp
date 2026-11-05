// roc 2012-06 00b2186e  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b2186e
//
// 00b2186e  b9f0a4e500           mov ecx, 0xe5a4f0
// 00b21873  e98ca4f5ff           jmp 0xa7bd04
// auto-matched from its assembly shape

struct T_func_00b2186e { void m(); };
extern T_func_00b2186e G1_func_00b2186e;
void func_00b2186e()
{
    G1_func_00b2186e.m();
}
