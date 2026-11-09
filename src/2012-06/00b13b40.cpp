// roc 2012-06 00b13b40  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13b40
//
// 00b13b40  b95822e200           mov ecx, 0xe22258
// 00b13b45  e92665b9ff           jmp 0x6aa070
// auto-matched from its assembly shape

struct T_func_00b13b40 { void m(); };
extern T_func_00b13b40 G1_func_00b13b40;
void func_00b13b40()
{
    G1_func_00b13b40.m();
}
