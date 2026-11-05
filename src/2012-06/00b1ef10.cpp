// roc 2012-06 00b1ef10  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ef10
//
// 00b1ef10  b9681ae500           mov ecx, 0xe51a68
// 00b1ef15  e996b5d5ff           jmp 0x87a4b0
// auto-matched from its assembly shape

struct T_func_00b1ef10 { void m(); };
extern T_func_00b1ef10 G1_func_00b1ef10;
void func_00b1ef10()
{
    G1_func_00b1ef10.m();
}
