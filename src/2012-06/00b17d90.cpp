// roc 2012-06 00b17d90  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17d90
//
// 00b17d90  a1503ee300           mov eax, dword ptr [0xe33e50]
// 00b17d95  50                   push eax
// 00b17d96  e879a3e6ff           call 0x982114
// 00b17d9b  83c404               add esp, 4
// 00b17d9e  c705283ee3002c3cb400 mov dword ptr [0xe33e28], 0xb43c2c
// 00b17da8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b17d90(int);
void func_00b17d90()
{
    G4_func_00b17d90(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
