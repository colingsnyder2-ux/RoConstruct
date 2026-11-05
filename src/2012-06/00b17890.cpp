// roc 2012-06 00b17890  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17890
//
// 00b17890  b9f824e300           mov ecx, 0xe324f8
// 00b17895  e956b8c0ff           jmp 0x7230f0
// auto-matched from its assembly shape

struct T_func_00b17890 { void m(); };
extern T_func_00b17890 G1_func_00b17890;
void func_00b17890()
{
    G1_func_00b17890.m();
}
