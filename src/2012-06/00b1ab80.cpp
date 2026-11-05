// roc 2012-06 00b1ab80  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ab80
//
// 00b1ab80  b9d07fe300           mov ecx, 0xe37fd0
// 00b1ab85  e986f4c4ff           jmp 0x76a010
// auto-matched from its assembly shape

struct T_func_00b1ab80 { void m(); };
extern T_func_00b1ab80 G1_func_00b1ab80;
void func_00b1ab80()
{
    G1_func_00b1ab80.m();
}
