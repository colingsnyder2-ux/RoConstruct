// roc 2012-06 00b1aa60  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1aa60
//
// 00b1aa60  b9308ce300           mov ecx, 0xe38c30
// 00b1aa65  e95620c5ff           jmp 0x76cac0
// auto-matched from its assembly shape

struct T_func_00b1aa60 { void m(); };
extern T_func_00b1aa60 G1_func_00b1aa60;
void func_00b1aa60()
{
    G1_func_00b1aa60.m();
}
