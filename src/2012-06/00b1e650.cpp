// roc 2012-06 00b1e650  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e650
//
// 00b1e650  a12409e500           mov eax, dword ptr [0xe50924]
// 00b1e655  50                   push eax
// 00b1e656  e8b93ae6ff           call 0x982114
// 00b1e65b  83c404               add esp, 4
// 00b1e65e  c705f808e5002c3cb400 mov dword ptr [0xe508f8], 0xb43c2c
// 00b1e668  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e650(int);
void func_00b1e650()
{
    G4_func_00b1e650(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
