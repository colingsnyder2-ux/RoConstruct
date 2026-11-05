// roc 2012-06 00b1e150  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e150
//
// 00b1e150  a1cc00e500           mov eax, dword ptr [0xe500cc]
// 00b1e155  50                   push eax
// 00b1e156  e8b93fe6ff           call 0x982114
// 00b1e15b  83c404               add esp, 4
// 00b1e15e  c705a400e5002c3cb400 mov dword ptr [0xe500a4], 0xb43c2c
// 00b1e168  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e150(int);
void func_00b1e150()
{
    G4_func_00b1e150(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
