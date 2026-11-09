// roc 2012-06 00b1c330  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c330
//
// 00b1c330  b9e8aae400           mov ecx, 0xe4aae8
// 00b1c335  e9b65ba7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1c330 { void m(); };
extern T_func_00b1c330 G1_func_00b1c330;
void func_00b1c330()
{
    G1_func_00b1c330.m();
}
