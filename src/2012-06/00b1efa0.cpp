// roc 2012-06 00b1efa0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1efa0
//
// 00b1efa0  b9181be500           mov ecx, 0xe51b18
// 00b1efa5  e9462fa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1efa0 { void m(); };
extern T_func_00b1efa0 G1_func_00b1efa0;
void func_00b1efa0()
{
    G1_func_00b1efa0.m();
}
