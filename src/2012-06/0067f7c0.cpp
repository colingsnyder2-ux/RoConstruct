// roc 2012-06 0067f7c0  unit: VAuthoringSettings::?$FactoryProduct  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0067f7c0
//
// 0067f7c0  687ca2e100           push 0xe1a27c
// 0067f7c5  e896ca2f00           call 0x97c260
// 0067f7ca  59                   pop ecx
// 0067f7cb  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_0067f7c0;
extern void G1_func_0067f7c0(void*);
void func_0067f7c0()
{
    G1_func_0067f7c0(&G2_func_0067f7c0);
}
