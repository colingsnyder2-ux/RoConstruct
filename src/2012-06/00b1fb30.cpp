// roc 2012-06 00b1fb30  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1fb30
//
// 00b1fb30  b96038e500           mov ecx, 0xe53860
// 00b1fb35  e9b623a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1fb30 { void m(); };
extern T_func_00b1fb30 G1_func_00b1fb30;
void func_00b1fb30()
{
    G1_func_00b1fb30.m();
}
