// roc 2012-06 00b1a950  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1a950
//
// 00b1a950  b9e097e300           mov ecx, 0xe397e0
// 00b1a955  e9464ac5ff           jmp 0x76f3a0
// auto-matched from its assembly shape

struct T_func_00b1a950 { void m(); };
extern T_func_00b1a950 G1_func_00b1a950;
void func_00b1a950()
{
    G1_func_00b1a950.m();
}
