// roc 2012-06 00b14e00  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14e00
//
// 00b14e00  a15c9ee200           mov eax, dword ptr [0xe29e5c]
// 00b14e05  50                   push eax
// 00b14e06  e809d3e6ff           call 0x982114
// 00b14e0b  83c404               add esp, 4
// 00b14e0e  c705349ee2002c3cb400 mov dword ptr [0xe29e34], 0xb43c2c
// 00b14e18  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b14e00(int);
void func_00b14e00()
{
    G4_func_00b14e00(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
