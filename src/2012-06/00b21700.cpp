// roc 2012-06 00b21700  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b21700
//
// 00b21700  b98094e500           mov ecx, 0xe59480
// 00b21705  e96215e6ff           jmp 0x982c6c
// auto-matched from its assembly shape

struct T_func_00b21700 { void m(); };
extern T_func_00b21700 G1_func_00b21700;
void func_00b21700()
{
    G1_func_00b21700.m();
}
