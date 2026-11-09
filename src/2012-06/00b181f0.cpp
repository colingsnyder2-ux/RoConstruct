// roc 2012-06 00b181f0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b181f0
//
// 00b181f0  b9a054e300           mov ecx, 0xe354a0
// 00b181f5  e9f69ca7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b181f0 { void m(); };
extern T_func_00b181f0 G1_func_00b181f0;
void func_00b181f0()
{
    G1_func_00b181f0.m();
}
