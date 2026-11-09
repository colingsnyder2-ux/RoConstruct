// roc 2012-06 00b17100  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17100
//
// 00b17100  b95002e300           mov ecx, 0xe30250
// 00b17105  e9b600beff           jmp 0x6f71c0
// auto-matched from its assembly shape

struct T_func_00b17100 { void m(); };
extern T_func_00b17100 G1_func_00b17100;
void func_00b17100()
{
    G1_func_00b17100.m();
}
