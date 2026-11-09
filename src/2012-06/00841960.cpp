// roc 2012-06 00841960  unit: seg_00840000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00841960
//
// 00841960  681413e500           push 0xe51314
// 00841965  e8f6a81300           call 0x97c260
// 0084196a  59                   pop ecx
// 0084196b  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_00841960;
extern void G1_func_00841960(void*);
void func_00841960()
{
    G1_func_00841960(&G2_func_00841960);
}
