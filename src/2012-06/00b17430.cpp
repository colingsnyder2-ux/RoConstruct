// roc 2012-06 00b17430  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17430
//
// 00b17430  b99017e300           mov ecx, 0xe31790
// 00b17435  e9b6aaa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b17430 { void m(); };
extern T_func_00b17430 G1_func_00b17430;
void func_00b17430()
{
    G1_func_00b17430.m();
}
