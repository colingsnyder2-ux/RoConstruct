// roc 2012-06 00b20a50  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20a50
//
// 00b20a50  a1bc5ce500           mov eax, dword ptr [0xe55cbc]
// 00b20a55  50                   push eax
// 00b20a56  e8b916e6ff           call 0x982114
// 00b20a5b  83c404               add esp, 4
// 00b20a5e  c705945ce5002c3cb400 mov dword ptr [0xe55c94], 0xb43c2c
// 00b20a68  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20a50(int);
void func_00b20a50()
{
    G4_func_00b20a50(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
