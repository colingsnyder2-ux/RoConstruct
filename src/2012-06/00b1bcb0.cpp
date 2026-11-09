// roc 2012-06 00b1bcb0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1bcb0
//
// 00b1bcb0  b9809ee400           mov ecx, 0xe49e80
// 00b1bcb5  e93662a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1bcb0 { void m(); };
extern T_func_00b1bcb0 G1_func_00b1bcb0;
void func_00b1bcb0()
{
    G1_func_00b1bcb0.m();
}
