// roc 2012-06 00b217c0  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b217c0
//
// 00b217c0  b964a0e500           mov ecx, 0xe5a064
// 00b217c5  e99682edff           jmp 0x9f9a60
// auto-matched from its assembly shape

struct T_func_00b217c0 { void m(); };
extern T_func_00b217c0 G1_func_00b217c0;
void func_00b217c0()
{
    G1_func_00b217c0.m();
}
