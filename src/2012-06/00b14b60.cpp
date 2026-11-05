// roc 2012-06 00b14b60  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14b60
//
// 00b14b60  b99c7de200           mov ecx, 0xe27d9c
// 00b14b65  e986eaabff           jmp 0x5d35f0
// auto-matched from its assembly shape

struct T_func_00b14b60 { void m(); };
extern T_func_00b14b60 G1_func_00b14b60;
void func_00b14b60()
{
    G1_func_00b14b60.m();
}
