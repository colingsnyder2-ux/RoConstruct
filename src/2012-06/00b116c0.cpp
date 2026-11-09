// roc 2012-06 00b116c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b116c0
//
// 00b116c0  b9606fe100           mov ecx, 0xe16f60
// 00b116c5  e9a6e28fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b116c0 { void m(); };
extern T_func_00b116c0 G1_func_00b116c0;
void func_00b116c0()
{
    G1_func_00b116c0.m();
}
