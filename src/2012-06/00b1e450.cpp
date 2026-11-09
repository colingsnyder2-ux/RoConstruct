// roc 2012-06 00b1e450  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e450
//
// 00b1e450  a15805e500           mov eax, dword ptr [0xe50558]
// 00b1e455  50                   push eax
// 00b1e456  e8b93ce6ff           call 0x982114
// 00b1e45b  83c404               add esp, 4
// 00b1e45e  c7053005e5002c3cb400 mov dword ptr [0xe50530], 0xb43c2c
// 00b1e468  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e450(int);
void func_00b1e450()
{
    G4_func_00b1e450(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
