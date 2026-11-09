// roc 2012-06 00b21850  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b21850
//
// 00b21850  b964a4e500           mov ecx, 0xe5a464
// 00b21855  e9467af5ff           jmp 0xa792a0
// auto-matched from its assembly shape

struct T_func_00b21850 { void m(); };
extern T_func_00b21850 G1_func_00b21850;
void func_00b21850()
{
    G1_func_00b21850.m();
}
