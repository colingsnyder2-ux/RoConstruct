// roc 2012-06 00b11670  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11670
//
// 00b11670  b9e878e100           mov ecx, 0xe178e8
// 00b11675  e9f6e28fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b11670 { void m(); };
extern T_func_00b11670 G1_func_00b11670;
void func_00b11670()
{
    G1_func_00b11670.m();
}
