// roc 2012-06 00b17850  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17850
//
// 00b17850  b96022e300           mov ecx, 0xe32260
// 00b17855  e936b7c0ff           jmp 0x722f90
// auto-matched from its assembly shape

struct T_func_00b17850 { void m(); };
extern T_func_00b17850 G1_func_00b17850;
void func_00b17850()
{
    G1_func_00b17850.m();
}
