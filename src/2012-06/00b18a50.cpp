// roc 2012-06 00b18a50  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18a50
//
// 00b18a50  a1b46fe300           mov eax, dword ptr [0xe36fb4]
// 00b18a55  50                   push eax
// 00b18a56  e8b996e6ff           call 0x982114
// 00b18a5b  83c404               add esp, 4
// 00b18a5e  c7058c6fe3002c3cb400 mov dword ptr [0xe36f8c], 0xb43c2c
// 00b18a68  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b18a50(int);
void func_00b18a50()
{
    G4_func_00b18a50(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
