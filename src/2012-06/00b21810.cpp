// roc 2012-06 00b21810  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b21810
//
// 00b21810  b980a3e500           mov ecx, 0xe5a380
// 00b21815  e9c685f2ff           jmp 0xa49de0
// auto-matched from its assembly shape

struct T_func_00b21810 { void m(); };
extern T_func_00b21810 G1_func_00b21810;
void func_00b21810()
{
    G1_func_00b21810.m();
}
