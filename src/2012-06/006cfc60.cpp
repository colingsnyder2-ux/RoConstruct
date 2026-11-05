// roc 2012-06 006cfc60  unit: boost::io::too_many_args  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006cfc60
//
// 006cfc60  684c8ce200           push 0xe28c4c
// 006cfc65  e8f6c52a00           call 0x97c260
// 006cfc6a  59                   pop ecx
// 006cfc6b  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_006cfc60;
extern void G1_func_006cfc60(void*);
void func_006cfc60()
{
    G1_func_006cfc60(&G2_func_006cfc60);
}
