// roc 2012-06 00b20a10  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20a10
//
// 00b20a10  a1605ce500           mov eax, dword ptr [0xe55c60]
// 00b20a15  50                   push eax
// 00b20a16  e8f916e6ff           call 0x982114
// 00b20a1b  83c404               add esp, 4
// 00b20a1e  c705385ce5002c3cb400 mov dword ptr [0xe55c38], 0xb43c2c
// 00b20a28  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20a10(int);
void func_00b20a10()
{
    G4_func_00b20a10(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
