// roc 2012-06 00afa2b0  unit: seg_00af0000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00afa2b0
//
// 00afa2b0  6830bcba00           push 0xbabc30
// 00afa2b5  e82650b8ff           call 0x67f2e0
// 00afa2ba  83c404               add esp, 4
// 00afa2bd  a3745ee300           mov dword ptr [0xe35e74], eax
// 00afa2c2  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G3_OBJ;
extern int* G1_VALUE;
extern int __cdecl G2_func_00afa2b0(void*);
void func_00afa2b0()
{
    G1_VALUE = (int*)G2_func_00afa2b0(&G3_OBJ);
}
