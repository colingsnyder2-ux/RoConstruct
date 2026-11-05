// roc 2012-06 00b1ac70  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ac70
//
// 00b1ac70  b99070e400           mov ecx, 0xe47090
// 00b1ac75  e9f64c8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1ac70 { void m(); };
extern T_func_00b1ac70 G1_func_00b1ac70;
void func_00b1ac70()
{
    G1_func_00b1ac70.m();
}
