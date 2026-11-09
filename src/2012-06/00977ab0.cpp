// roc 2012-06 00977ab0  unit: RBX::VCEvent::?$sp_counted_impl_p  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00977ab0
//
// 00977ab0  6884a2e100           push 0xe1a284
// 00977ab5  e8a6470000           call 0x97c260
// 00977aba  59                   pop ecx
// 00977abb  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_00977ab0;
extern void G1_func_00977ab0(void*);
void func_00977ab0()
{
    G1_func_00977ab0(&G2_func_00977ab0);
}
