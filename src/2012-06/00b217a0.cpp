// roc 2012-06 00b217a0  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b217a0
//
// 00b217a0  b954a0e500           mov ecx, 0xe5a054
// 00b217a5  e94681f7ff           jmp 0xa998f0
// auto-matched from its assembly shape

struct T_func_00b217a0 { void m(); };
extern T_func_00b217a0 G1_func_00b217a0;
void func_00b217a0()
{
    G1_func_00b217a0.m();
}
