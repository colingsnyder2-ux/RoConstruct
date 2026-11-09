// roc 2012-06 00aeb400  unit: seg_00ae0000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00aeb400
//
// 00aeb400  682025b100           push 0xb12520
// 00aeb405  e8eb7de9ff           call 0x9831f5
// 00aeb40a  59                   pop ecx
// 00aeb40b  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_00aeb400;
extern void G1_func_00aeb400(void*);
void func_00aeb400()
{
    G1_func_00aeb400(&G2_func_00aeb400);
}
