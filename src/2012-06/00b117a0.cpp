// roc 2012-06 00b117a0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b117a0
//
// 00b117a0  b9dc7ce100           mov ecx, 0xe17cdc
// 00b117a5  e9f6e68fff           jmp 0x40fea0
// auto-matched from its assembly shape

struct T_func_00b117a0 { void m(); };
extern T_func_00b117a0 G1_func_00b117a0;
void func_00b117a0()
{
    G1_func_00b117a0.m();
}
