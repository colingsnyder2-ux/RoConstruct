// roc 2012-06 00b12910  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12910
//
// 00b12910  b998c1e100           mov ecx, 0xe1c198
// 00b12915  e9d6069aff           jmp 0x4b2ff0
// auto-matched from its assembly shape

struct T_func_00b12910 { void m(); };
extern T_func_00b12910 G1_func_00b12910;
void func_00b12910()
{
    G1_func_00b12910.m();
}
