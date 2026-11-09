// roc 2012-06 00b126d0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b126d0
//
// 00b126d0  b9d0a0e100           mov ecx, 0xe1a0d0
// 00b126d5  e9b63496ff           jmp 0x475b90
// auto-matched from its assembly shape

struct T_func_00b126d0 { void m(); };
extern T_func_00b126d0 G1_func_00b126d0;
void func_00b126d0()
{
    G1_func_00b126d0.m();
}
