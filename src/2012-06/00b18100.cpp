// roc 2012-06 00b18100  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18100
//
// 00b18100  a1dc4be300           mov eax, dword ptr [0xe34bdc]
// 00b18105  50                   push eax
// 00b18106  e809a0e6ff           call 0x982114
// 00b1810b  83c404               add esp, 4
// 00b1810e  c705b44be3002c3cb400 mov dword ptr [0xe34bb4], 0xb43c2c
// 00b18118  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b18100(int);
void func_00b18100()
{
    G4_func_00b18100(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
