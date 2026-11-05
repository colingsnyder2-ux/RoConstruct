// roc 2012-06 00b1d090  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d090
//
// 00b1d090  b9a0dee400           mov ecx, 0xe4dea0
// 00b1d095  e9a629d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1d090 { void m(); };
extern T_func_00b1d090 G1_func_00b1d090;
void func_00b1d090()
{
    G1_func_00b1d090.m();
}
