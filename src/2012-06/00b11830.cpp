// roc 2012-06 00b11830  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11830
//
// 00b11830  b91881e100           mov ecx, 0xe18118
// 00b11835  e966df90ff           jmp 0x41f7a0
// auto-matched from its assembly shape

struct T_func_00b11830 { void m(); };
extern T_func_00b11830 G1_func_00b11830;
void func_00b11830()
{
    G1_func_00b11830.m();
}
