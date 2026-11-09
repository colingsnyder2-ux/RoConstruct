// roc 2012-06 00b14f00  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14f00
//
// 00b14f00  a1709fe200           mov eax, dword ptr [0xe29f70]
// 00b14f05  50                   push eax
// 00b14f06  e809d2e6ff           call 0x982114
// 00b14f0b  83c404               add esp, 4
// 00b14f0e  c705489fe2002c3cb400 mov dword ptr [0xe29f48], 0xb43c2c
// 00b14f18  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b14f00(int);
void func_00b14f00()
{
    G4_func_00b14f00(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
