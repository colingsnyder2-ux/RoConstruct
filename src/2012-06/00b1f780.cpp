// roc 2012-06 00b1f780  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f780
//
// 00b1f780  a1d02de500           mov eax, dword ptr [0xe52dd0]
// 00b1f785  50                   push eax
// 00b1f786  e88929e6ff           call 0x982114
// 00b1f78b  83c404               add esp, 4
// 00b1f78e  c705a82de5002c3cb400 mov dword ptr [0xe52da8], 0xb43c2c
// 00b1f798  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f780(int);
void func_00b1f780()
{
    G4_func_00b1f780(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
