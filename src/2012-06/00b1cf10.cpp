// roc 2012-06 00b1cf10  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1cf10
//
// 00b1cf10  a1d4dce400           mov eax, dword ptr [0xe4dcd4]
// 00b1cf15  50                   push eax
// 00b1cf16  e8f951e6ff           call 0x982114
// 00b1cf1b  83c404               add esp, 4
// 00b1cf1e  c705acdce4002c3cb400 mov dword ptr [0xe4dcac], 0xb43c2c
// 00b1cf28  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1cf10(int);
void func_00b1cf10()
{
    G4_func_00b1cf10(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
