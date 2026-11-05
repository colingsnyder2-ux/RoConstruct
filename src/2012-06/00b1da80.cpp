// roc 2012-06 00b1da80  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1da80
//
// 00b1da80  b978f1e400           mov ecx, 0xe4f178
// 00b1da85  e9d6d9ccff           jmp 0x7eb460
// auto-matched from its assembly shape

struct T_func_00b1da80 { void m(); };
extern T_func_00b1da80 G1_func_00b1da80;
void func_00b1da80()
{
    G1_func_00b1da80.m();
}
