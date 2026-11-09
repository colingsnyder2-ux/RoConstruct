// roc 2012-06 00b11710  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11710
//
// 00b11710  b9b87ce100           mov ecx, 0xe17cb8
// 00b11715  e9c60b90ff           jmp 0x4122e0
// auto-matched from its assembly shape

struct T_func_00b11710 { void m(); };
extern T_func_00b11710 G1_func_00b11710;
void func_00b11710()
{
    G1_func_00b11710.m();
}
