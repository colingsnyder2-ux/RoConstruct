// roc 2012-06 00b1fee0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1fee0
//
// 00b1fee0  a1e84de500           mov eax, dword ptr [0xe54de8]
// 00b1fee5  50                   push eax
// 00b1fee6  e82922e6ff           call 0x982114
// 00b1feeb  83c404               add esp, 4
// 00b1feee  c705c04de5002c3cb400 mov dword ptr [0xe54dc0], 0xb43c2c
// 00b1fef8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1fee0(int);
void func_00b1fee0()
{
    G4_func_00b1fee0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
