// roc 2012-06 00b14380  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14380
//
// 00b14380  b9503ee200           mov ecx, 0xe23e50
// 00b14385  e9e6b58fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b14380 { void m(); };
extern T_func_00b14380 G1_func_00b14380;
void func_00b14380()
{
    G1_func_00b14380.m();
}
