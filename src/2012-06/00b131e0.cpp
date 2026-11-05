// roc 2012-06 00b131e0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b131e0
//
// 00b131e0  b9c8e2e100           mov ecx, 0xe1e2c8
// 00b131e5  e936fda0ff           jmp 0x522f20
// auto-matched from its assembly shape

struct T_func_00b131e0 { void m(); };
extern T_func_00b131e0 G1_func_00b131e0;
void func_00b131e0()
{
    G1_func_00b131e0.m();
}
