// roc 2012-06 00b1b8a0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b8a0
//
// 00b1b8a0  b91095e400           mov ecx, 0xe49510
// 00b1b8a5  e94666a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1b8a0 { void m(); };
extern T_func_00b1b8a0 G1_func_00b1b8a0;
void func_00b1b8a0()
{
    G1_func_00b1b8a0.m();
}
