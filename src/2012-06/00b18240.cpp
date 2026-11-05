// roc 2012-06 00b18240  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18240
//
// 00b18240  b9e854e300           mov ecx, 0xe354e8
// 00b18245  e9a69ca7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b18240 { void m(); };
extern T_func_00b18240 G1_func_00b18240;
void func_00b18240()
{
    G1_func_00b18240.m();
}
