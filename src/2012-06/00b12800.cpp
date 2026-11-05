// roc 2012-06 00b12800  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12800
//
// 00b12800  b934a9e100           mov ecx, 0xe1a934
// 00b12805  e9766598ff           jmp 0x498d80
// auto-matched from its assembly shape

struct T_func_00b12800 { void m(); };
extern T_func_00b12800 G1_func_00b12800;
void func_00b12800()
{
    G1_func_00b12800.m();
}
