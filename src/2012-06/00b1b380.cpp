// roc 2012-06 00b1b380  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b380
//
// 00b1b380  b9048be400           mov ecx, 0xe48b04
// 00b1b385  e9d636c6ff           jmp 0x77ea60
// auto-matched from its assembly shape

struct T_func_00b1b380 { void m(); };
extern T_func_00b1b380 G1_func_00b1b380;
void func_00b1b380()
{
    G1_func_00b1b380.m();
}
