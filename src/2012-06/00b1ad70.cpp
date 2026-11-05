// roc 2012-06 00b1ad70  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ad70
//
// 00b1ad70  b91052e400           mov ecx, 0xe45210
// 00b1ad75  e9f64b8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1ad70 { void m(); };
extern T_func_00b1ad70 G1_func_00b1ad70;
void func_00b1ad70()
{
    G1_func_00b1ad70.m();
}
