// roc 2012-06 00b1c080  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c080
//
// 00b1c080  b9d0a6e400           mov ecx, 0xe4a6d0
// 00b1c085  e9665ea7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1c080 { void m(); };
extern T_func_00b1c080 G1_func_00b1c080;
void func_00b1c080()
{
    G1_func_00b1c080.m();
}
