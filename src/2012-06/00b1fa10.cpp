// roc 2012-06 00b1fa10  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1fa10
//
// 00b1fa10  b9d433e500           mov ecx, 0xe533d4
// 00b1fa15  e9d624a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1fa10 { void m(); };
extern T_func_00b1fa10 G1_func_00b1fa10;
void func_00b1fa10()
{
    G1_func_00b1fa10.m();
}
