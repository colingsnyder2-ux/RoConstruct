// roc 2012-06 00b17880  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17880
//
// 00b17880  b9e822e300           mov ecx, 0xe322e8
// 00b17885  e906b7c0ff           jmp 0x722f90
// auto-matched from its assembly shape

struct T_func_00b17880 { void m(); };
extern T_func_00b17880 G1_func_00b17880;
void func_00b17880()
{
    G1_func_00b17880.m();
}
