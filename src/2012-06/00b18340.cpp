// roc 2012-06 00b18340  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18340
//
// 00b18340  a1e456e300           mov eax, dword ptr [0xe356e4]
// 00b18345  50                   push eax
// 00b18346  e8c99de6ff           call 0x982114
// 00b1834b  83c404               add esp, 4
// 00b1834e  c705bc56e3002c3cb400 mov dword ptr [0xe356bc], 0xb43c2c
// 00b18358  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b18340(int);
void func_00b18340()
{
    G4_func_00b18340(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
