// roc 2012-06 00b20a30  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20a30
//
// 00b20a30  a1345ce500           mov eax, dword ptr [0xe55c34]
// 00b20a35  50                   push eax
// 00b20a36  e8d916e6ff           call 0x982114
// 00b20a3b  83c404               add esp, 4
// 00b20a3e  c7050c5ce5002c3cb400 mov dword ptr [0xe55c0c], 0xb43c2c
// 00b20a48  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20a30(int);
void func_00b20a30()
{
    G4_func_00b20a30(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
