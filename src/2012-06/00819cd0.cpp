// roc 2012-06 00819cd0  unit: RBX::ChatService  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00819cd0
//
// 00819cd0  68c007e500           push 0xe507c0
// 00819cd5  e886251600           call 0x97c260
// 00819cda  59                   pop ecx
// 00819cdb  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_00819cd0;
extern void G1_func_00819cd0(void*);
void func_00819cd0()
{
    G1_func_00819cd0(&G2_func_00819cd0);
}
