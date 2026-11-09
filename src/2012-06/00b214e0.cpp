// roc 2012-06 00b214e0  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b214e0
//
// 00b214e0  b90080e500           mov ecx, 0xe58000
// 00b214e5  e98606e5ff           jmp 0x971b70
// auto-matched from its assembly shape

struct T_func_00b214e0 { void m(); };
extern T_func_00b214e0 G1_func_00b214e0;
void func_00b214e0()
{
    G1_func_00b214e0.m();
}
