// roc 2012-06 00b1dd40  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1dd40
//
// 00b1dd40  b9c8f7e400           mov ecx, 0xe4f7c8
// 00b1dd45  e9f61cd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1dd40 { void m(); };
extern T_func_00b1dd40 G1_func_00b1dd40;
void func_00b1dd40()
{
    G1_func_00b1dd40.m();
}
