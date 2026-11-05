// roc 2012-06 00b1e490  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e490
//
// 00b1e490  a19c04e500           mov eax, dword ptr [0xe5049c]
// 00b1e495  50                   push eax
// 00b1e496  e8793ce6ff           call 0x982114
// 00b1e49b  83c404               add esp, 4
// 00b1e49e  c7057404e5002c3cb400 mov dword ptr [0xe50474], 0xb43c2c
// 00b1e4a8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e490(int);
void func_00b1e490()
{
    G4_func_00b1e490(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
