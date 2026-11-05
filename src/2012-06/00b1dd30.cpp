// roc 2012-06 00b1dd30  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1dd30
//
// 00b1dd30  b9d0f4e400           mov ecx, 0xe4f4d0
// 00b1dd35  e9061dd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1dd30 { void m(); };
extern T_func_00b1dd30 G1_func_00b1dd30;
void func_00b1dd30()
{
    G1_func_00b1dd30.m();
}
