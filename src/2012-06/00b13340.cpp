// roc 2012-06 00b13340  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13340
//
// 00b13340  b9b8ede100           mov ecx, 0xe1edb8
// 00b13345  e926c68fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b13340 { void m(); };
extern T_func_00b13340 G1_func_00b13340;
void func_00b13340()
{
    G1_func_00b13340.m();
}
