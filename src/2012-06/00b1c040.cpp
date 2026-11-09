// roc 2012-06 00b1c040  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c040
//
// 00b1c040  a1cca6e400           mov eax, dword ptr [0xe4a6cc]
// 00b1c045  50                   push eax
// 00b1c046  e8c960e6ff           call 0x982114
// 00b1c04b  83c404               add esp, 4
// 00b1c04e  c705a4a6e4002c3cb400 mov dword ptr [0xe4a6a4], 0xb43c2c
// 00b1c058  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1c040(int);
void func_00b1c040()
{
    G4_func_00b1c040(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
