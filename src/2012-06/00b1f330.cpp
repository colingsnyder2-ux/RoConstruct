// roc 2012-06 00b1f330  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f330
//
// 00b1f330  a19826e500           mov eax, dword ptr [0xe52698]
// 00b1f335  50                   push eax
// 00b1f336  e8d92de6ff           call 0x982114
// 00b1f33b  83c404               add esp, 4
// 00b1f33e  c7056c26e5002c3cb400 mov dword ptr [0xe5266c], 0xb43c2c
// 00b1f348  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f330(int);
void func_00b1f330()
{
    G4_func_00b1f330(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
