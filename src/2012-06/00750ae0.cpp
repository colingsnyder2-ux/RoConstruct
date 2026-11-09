// roc 2012-06 00750ae0  unit: RBX::PartInstance  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00750ae0
//
// 00750ae0  688ca2e100           push 0xe1a28c
// 00750ae5  e876b72200           call 0x97c260
// 00750aea  59                   pop ecx
// 00750aeb  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_00750ae0;
extern void G1_func_00750ae0(void*);
void func_00750ae0()
{
    G1_func_00750ae0(&G2_func_00750ae0);
}
