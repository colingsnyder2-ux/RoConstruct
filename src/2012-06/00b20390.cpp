// roc 2012-06 00b20390  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20390
//
// 00b20390  a11851e500           mov eax, dword ptr [0xe55118]
// 00b20395  50                   push eax
// 00b20396  e8791de6ff           call 0x982114
// 00b2039b  83c404               add esp, 4
// 00b2039e  c705ec50e5002c3cb400 mov dword ptr [0xe550ec], 0xb43c2c
// 00b203a8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20390(int);
void func_00b20390()
{
    G4_func_00b20390(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
