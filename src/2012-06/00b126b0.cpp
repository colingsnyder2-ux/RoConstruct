// roc 2012-06 00b126b0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b126b0
//
// 00b126b0  b93ca4e100           mov ecx, 0xe1a43c
// 00b126b5  e9a61e96ff           jmp 0x474560
// auto-matched from its assembly shape

struct T_func_00b126b0 { void m(); };
extern T_func_00b126b0 G1_func_00b126b0;
void func_00b126b0()
{
    G1_func_00b126b0.m();
}
