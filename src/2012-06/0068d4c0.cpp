// roc 2012-06 0068d4c0  unit: RBX::ModelInstance  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0068d4c0
//
// 0068d4c0  6880a2e100           push 0xe1a280
// 0068d4c5  e896ed2e00           call 0x97c260
// 0068d4ca  59                   pop ecx
// 0068d4cb  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_0068d4c0;
extern void G1_func_0068d4c0(void*);
void func_0068d4c0()
{
    G1_func_0068d4c0(&G2_func_0068d4c0);
}
