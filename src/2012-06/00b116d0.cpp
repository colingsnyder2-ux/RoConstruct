// roc 2012-06 00b116d0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b116d0
//
// 00b116d0  b9786de100           mov ecx, 0xe16d78
// 00b116d5  e996e28fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b116d0 { void m(); };
extern T_func_00b116d0 G1_func_00b116d0;
void func_00b116d0()
{
    G1_func_00b116d0.m();
}
