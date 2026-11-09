// roc 2012-06 00b14370  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14370
//
// 00b14370  b93840e200           mov ecx, 0xe24038
// 00b14375  e9f6b58fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b14370 { void m(); };
extern T_func_00b14370 G1_func_00b14370;
void func_00b14370()
{
    G1_func_00b14370.m();
}
