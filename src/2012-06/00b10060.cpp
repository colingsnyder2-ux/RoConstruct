// roc 2012-06 00b10060  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10060
//
// 00b10060  b95e6de500           mov ecx, 0xe56d5e
// 00b10065  e9965ceeff           jmp 0x9f5d00
// auto-matched from its assembly shape

struct T_func_00b10060 { void m(); };
extern T_func_00b10060 G1_func_00b10060;
void func_00b10060()
{
    G1_func_00b10060.m();
}
