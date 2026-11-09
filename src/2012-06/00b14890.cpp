// roc 2012-06 00b14890  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14890
//
// 00b14890  b9304ee200           mov ecx, 0xe24e30
// 00b14895  e956d6a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b14890 { void m(); };
extern T_func_00b14890 G1_func_00b14890;
void func_00b14890()
{
    G1_func_00b14890.m();
}
