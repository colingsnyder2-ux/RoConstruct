// roc 2012-06 00b17600  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17600
//
// 00b17600  b9f01ae300           mov ecx, 0xe31af0
// 00b17605  e9e6ebbfff           jmp 0x7161f0
// auto-matched from its assembly shape

struct T_func_00b17600 { void m(); };
extern T_func_00b17600 G1_func_00b17600;
void func_00b17600()
{
    G1_func_00b17600.m();
}
