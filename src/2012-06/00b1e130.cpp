// roc 2012-06 00b1e130  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e130
//
// 00b1e130  a100ffe400           mov eax, dword ptr [0xe4ff00]
// 00b1e135  50                   push eax
// 00b1e136  e8d93fe6ff           call 0x982114
// 00b1e13b  83c404               add esp, 4
// 00b1e13e  c705d8fee4002c3cb400 mov dword ptr [0xe4fed8], 0xb43c2c
// 00b1e148  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e130(int);
void func_00b1e130()
{
    G4_func_00b1e130(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
