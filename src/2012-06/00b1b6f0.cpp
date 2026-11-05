// roc 2012-06 00b1b6f0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b6f0
//
// 00b1b6f0  b9688ee400           mov ecx, 0xe48e68
// 00b1b6f5  e94643d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1b6f0 { void m(); };
extern T_func_00b1b6f0 G1_func_00b1b6f0;
void func_00b1b6f0()
{
    G1_func_00b1b6f0.m();
}
