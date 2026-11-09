// roc 2012-06 00b127a0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b127a0
//
// 00b127a0  b964a6e100           mov ecx, 0xe1a664
// 00b127a5  e9262d97ff           jmp 0x4854d0
// auto-matched from its assembly shape

struct T_func_00b127a0 { void m(); };
extern T_func_00b127a0 G1_func_00b127a0;
void func_00b127a0()
{
    G1_func_00b127a0.m();
}
