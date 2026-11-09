// roc 2012-06 00b17220  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17220
//
// 00b17220  b9880ae300           mov ecx, 0xe30a88
// 00b17225  e946878fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b17220 { void m(); };
extern T_func_00b17220 G1_func_00b17220;
void func_00b17220()
{
    G1_func_00b17220.m();
}
