// roc 2012-06 00b12410  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12410
//
// 00b12410  b93092e100           mov ecx, 0xe19230
// 00b12415  e9164395ff           jmp 0x466730
// auto-matched from its assembly shape

struct T_func_00b12410 { void m(); };
extern T_func_00b12410 G1_func_00b12410;
void func_00b12410()
{
    G1_func_00b12410.m();
}
