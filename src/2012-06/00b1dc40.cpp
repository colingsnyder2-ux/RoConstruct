// roc 2012-06 00b1dc40  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1dc40
//
// 00b1dc40  b948fbe400           mov ecx, 0xe4fb48
// 00b1dc45  e9a642a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1dc40 { void m(); };
extern T_func_00b1dc40 G1_func_00b1dc40;
void func_00b1dc40()
{
    G1_func_00b1dc40.m();
}
