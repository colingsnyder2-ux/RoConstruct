// roc 2012-06 00b21820  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b21820
//
// 00b21820  b9b0a3e500           mov ecx, 0xe5a3b0
// 00b21825  e9864af4ff           jmp 0xa662b0
// auto-matched from its assembly shape

struct T_func_00b21820 { void m(); };
extern T_func_00b21820 G1_func_00b21820;
void func_00b21820()
{
    G1_func_00b21820.m();
}
