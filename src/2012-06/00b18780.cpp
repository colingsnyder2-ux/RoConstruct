// roc 2012-06 00b18780  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18780
//
// 00b18780  a1305de300           mov eax, dword ptr [0xe35d30]
// 00b18785  50                   push eax
// 00b18786  e88999e6ff           call 0x982114
// 00b1878b  83c404               add esp, 4
// 00b1878e  c705085de3002c3cb400 mov dword ptr [0xe35d08], 0xb43c2c
// 00b18798  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b18780(int);
void func_00b18780()
{
    G4_func_00b18780(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
