// roc 2012-06 00b16bf0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16bf0
//
// 00b16bf0  a110f3e200           mov eax, dword ptr [0xe2f310]
// 00b16bf5  50                   push eax
// 00b16bf6  e819b5e6ff           call 0x982114
// 00b16bfb  83c404               add esp, 4
// 00b16bfe  c705e8f2e2002c3cb400 mov dword ptr [0xe2f2e8], 0xb43c2c
// 00b16c08  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b16bf0(int);
void func_00b16bf0()
{
    G4_func_00b16bf0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
