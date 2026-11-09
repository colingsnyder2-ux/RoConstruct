// roc 2012-06 00b1d210  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d210
//
// 00b1d210  a108e8e400           mov eax, dword ptr [0xe4e808]
// 00b1d215  50                   push eax
// 00b1d216  e8f94ee6ff           call 0x982114
// 00b1d21b  83c404               add esp, 4
// 00b1d21e  c705e0e7e4002c3cb400 mov dword ptr [0xe4e7e0], 0xb43c2c
// 00b1d228  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1d210(int);
void func_00b1d210()
{
    G4_func_00b1d210(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
