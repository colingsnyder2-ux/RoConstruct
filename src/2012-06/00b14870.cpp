// roc 2012-06 00b14870  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14870
//
// 00b14870  b9804ee200           mov ecx, 0xe24e80
// 00b14875  e9867da6ff           jmp 0x57c600
// auto-matched from its assembly shape

struct T_func_00b14870 { void m(); };
extern T_func_00b14870 G1_func_00b14870;
void func_00b14870()
{
    G1_func_00b14870.m();
}
