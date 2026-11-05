// roc 2012-06 00b18a20  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18a20
//
// 00b18a20  b9c86be300           mov ecx, 0xe36bc8
// 00b18a25  e9c694a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b18a20 { void m(); };
extern T_func_00b18a20 G1_func_00b18a20;
void func_00b18a20()
{
    G1_func_00b18a20.m();
}
