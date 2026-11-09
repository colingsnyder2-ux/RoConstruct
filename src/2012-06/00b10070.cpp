// roc 2012-06 00b10070  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10070
//
// 00b10070  b9606de500           mov ecx, 0xe56d60
// 00b10075  e9865ceeff           jmp 0x9f5d00
// auto-matched from its assembly shape

struct T_func_00b10070 { void m(); };
extern T_func_00b10070 G1_func_00b10070;
void func_00b10070()
{
    G1_func_00b10070.m();
}
