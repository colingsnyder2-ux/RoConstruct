// roc 2012-06 00b1ac80  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ac80
//
// 00b1ac80  b9a86ee400           mov ecx, 0xe46ea8
// 00b1ac85  e9e64c8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1ac80 { void m(); };
extern T_func_00b1ac80 G1_func_00b1ac80;
void func_00b1ac80()
{
    G1_func_00b1ac80.m();
}
