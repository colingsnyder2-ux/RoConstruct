// roc 2012-06 00b13350  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13350
//
// 00b13350  b9d0ebe100           mov ecx, 0xe1ebd0
// 00b13355  e916c68fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b13350 { void m(); };
extern T_func_00b13350 G1_func_00b13350;
void func_00b13350()
{
    G1_func_00b13350.m();
}
