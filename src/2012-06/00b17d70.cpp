// roc 2012-06 00b17d70  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17d70
//
// 00b17d70  a17c3ee300           mov eax, dword ptr [0xe33e7c]
// 00b17d75  50                   push eax
// 00b17d76  e899a3e6ff           call 0x982114
// 00b17d7b  83c404               add esp, 4
// 00b17d7e  c705543ee3002c3cb400 mov dword ptr [0xe33e54], 0xb43c2c
// 00b17d88  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b17d70(int);
void func_00b17d70()
{
    G4_func_00b17d70(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
