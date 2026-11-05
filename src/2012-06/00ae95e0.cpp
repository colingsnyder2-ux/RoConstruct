// roc 2012-06 00ae95e0  unit: seg_00ae0000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00ae95e0
//
// 00ae95e0  681014b100           push 0xb11410
// 00ae95e5  e80b9ce9ff           call 0x9831f5
// 00ae95ea  59                   pop ecx
// 00ae95eb  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_00ae95e0;
extern void G1_func_00ae95e0(void*);
void func_00ae95e0()
{
    G1_func_00ae95e0(&G2_func_00ae95e0);
}
