// roc 2012-06 00b1fb00  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1fb00
//
// 00b1fb00  b98835e500           mov ecx, 0xe53588
// 00b1fb05  e9e623a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1fb00 { void m(); };
extern T_func_00b1fb00 G1_func_00b1fb00;
void func_00b1fb00()
{
    G1_func_00b1fb00.m();
}
