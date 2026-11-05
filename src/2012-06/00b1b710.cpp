// roc 2012-06 00b1b710  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b710
//
// 00b1b710  b9b88fe400           mov ecx, 0xe48fb8
// 00b1b715  e92643d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1b710 { void m(); };
extern T_func_00b1b710 G1_func_00b1b710;
void func_00b1b710()
{
    G1_func_00b1b710.m();
}
