// roc 2012-06 00b1c370  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c370
//
// 00b1c370  a144aee400           mov eax, dword ptr [0xe4ae44]
// 00b1c375  50                   push eax
// 00b1c376  e8995de6ff           call 0x982114
// 00b1c37b  83c404               add esp, 4
// 00b1c37e  c7051caee4002c3cb400 mov dword ptr [0xe4ae1c], 0xb43c2c
// 00b1c388  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1c370(int);
void func_00b1c370()
{
    G4_func_00b1c370(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
