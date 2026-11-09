// roc 2012-06 00841950  unit: seg_00840000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00841950
//
// 00841950  681013e500           push 0xe51310
// 00841955  e806a91300           call 0x97c260
// 0084195a  59                   pop ecx
// 0084195b  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_00841950;
extern void G1_func_00841950(void*);
void func_00841950()
{
    G1_func_00841950(&G2_func_00841950);
}
