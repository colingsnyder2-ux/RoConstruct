// roc 2012-06 00b1bc70  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1bc70
//
// 00b1bc70  b908a1e400           mov ecx, 0xe4a108
// 00b1bc75  e97662a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1bc70 { void m(); };
extern T_func_00b1bc70 G1_func_00b1bc70;
void func_00b1bc70()
{
    G1_func_00b1bc70.m();
}
