// roc 2012-06 00b1de60  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1de60
//
// 00b1de60  b908f9e400           mov ecx, 0xe4f908
// 00b1de65  e98640a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1de60 { void m(); };
extern T_func_00b1de60 G1_func_00b1de60;
void func_00b1de60()
{
    G1_func_00b1de60.m();
}
