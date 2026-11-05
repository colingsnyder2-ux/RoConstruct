// roc 2012-06 00b17840  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17840
//
// 00b17840  b9a822e300           mov ecx, 0xe322a8
// 00b17845  e906f2c7ff           jmp 0x796a50
// auto-matched from its assembly shape

struct T_func_00b17840 { void m(); };
extern T_func_00b17840 G1_func_00b17840;
void func_00b17840()
{
    G1_func_00b17840.m();
}
