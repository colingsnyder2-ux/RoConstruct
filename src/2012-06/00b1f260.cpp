// roc 2012-06 00b1f260  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f260
//
// 00b1f260  b9a01ee500           mov ecx, 0xe51ea0
// 00b1f265  e9d607d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1f260 { void m(); };
extern T_func_00b1f260 G1_func_00b1f260;
void func_00b1f260()
{
    G1_func_00b1f260.m();
}
