// roc 2012-06 00b1ab50  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ab50
//
// 00b1ab50  b9e081e300           mov ecx, 0xe381e0
// 00b1ab55  e9d6fcc4ff           jmp 0x76a830
// auto-matched from its assembly shape

struct T_func_00b1ab50 { void m(); };
extern T_func_00b1ab50 G1_func_00b1ab50;
void func_00b1ab50()
{
    G1_func_00b1ab50.m();
}
