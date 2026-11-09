// roc 2012-06 00b17860  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17860
//
// 00b17860  b9502be300           mov ecx, 0xe32b50
// 00b17865  e926b3c0ff           jmp 0x722b90
// auto-matched from its assembly shape

struct T_func_00b17860 { void m(); };
extern T_func_00b17860 G1_func_00b17860;
void func_00b17860()
{
    G1_func_00b17860.m();
}
