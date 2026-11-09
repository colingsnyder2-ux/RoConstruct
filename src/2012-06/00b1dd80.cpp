// roc 2012-06 00b1dd80  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1dd80
//
// 00b1dd80  b950f9e400           mov ecx, 0xe4f950
// 00b1dd85  e96641a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1dd80 { void m(); };
extern T_func_00b1dd80 G1_func_00b1dd80;
void func_00b1dd80()
{
    G1_func_00b1dd80.m();
}
