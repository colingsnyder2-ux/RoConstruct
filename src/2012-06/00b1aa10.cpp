// roc 2012-06 00b1aa10  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1aa10
//
// 00b1aa10  b9a08fe300           mov ecx, 0xe38fa0
// 00b1aa15  e9c62dc5ff           jmp 0x76d7e0
// auto-matched from its assembly shape

struct T_func_00b1aa10 { void m(); };
extern T_func_00b1aa10 G1_func_00b1aa10;
void func_00b1aa10()
{
    G1_func_00b1aa10.m();
}
