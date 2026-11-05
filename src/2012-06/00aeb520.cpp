// roc 2012-06 00aeb520  unit: seg_00ae0000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00aeb520
//
// 00aeb520  680027b100           push 0xb12700
// 00aeb525  e8cb7ce9ff           call 0x9831f5
// 00aeb52a  59                   pop ecx
// 00aeb52b  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_00aeb520;
extern void G1_func_00aeb520(void*);
void func_00aeb520()
{
    G1_func_00aeb520(&G2_func_00aeb520);
}
