// roc 2012-06 00b10090  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10090
//
// 00b10090  b9806de500           mov ecx, 0xe56d80
// 00b10095  e9665ceeff           jmp 0x9f5d00
// auto-matched from its assembly shape

struct T_func_00b10090 { void m(); };
extern T_func_00b10090 G1_func_00b10090;
void func_00b10090()
{
    G1_func_00b10090.m();
}
