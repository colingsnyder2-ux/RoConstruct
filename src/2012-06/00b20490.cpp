// roc 2012-06 00b20490  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20490
//
// 00b20490  b9b050e500           mov ecx, 0xe550b0
// 00b20495  e9561aa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b20490 { void m(); };
extern T_func_00b20490 G1_func_00b20490;
void func_00b20490()
{
    G1_func_00b20490.m();
}
