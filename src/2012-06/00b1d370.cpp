// roc 2012-06 00b1d370  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d370
//
// 00b1d370  a1e4e5e400           mov eax, dword ptr [0xe4e5e4]
// 00b1d375  50                   push eax
// 00b1d376  e8994de6ff           call 0x982114
// 00b1d37b  83c404               add esp, 4
// 00b1d37e  c705bce5e4002c3cb400 mov dword ptr [0xe4e5bc], 0xb43c2c
// 00b1d388  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1d370(int);
void func_00b1d370()
{
    G4_func_00b1d370(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
