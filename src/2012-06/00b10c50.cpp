// roc 2012-06 00b10c50  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10c50
//
// 00b10c50  686017b200           push 0xb21760
// 00b10c55  e89b25e7ff           call 0x9831f5
// 00b10c5a  59                   pop ecx
// 00b10c5b  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_00b10c50;
extern void G1_func_00b10c50(void*);
void func_00b10c50()
{
    G1_func_00b10c50(&G2_func_00b10c50);
}
