// roc 2012-06 00b1c510  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c510
//
// 00b1c510  a1ecb0e400           mov eax, dword ptr [0xe4b0ec]
// 00b1c515  50                   push eax
// 00b1c516  e8f95be6ff           call 0x982114
// 00b1c51b  83c404               add esp, 4
// 00b1c51e  c705c0b0e4002c3cb400 mov dword ptr [0xe4b0c0], 0xb43c2c
// 00b1c528  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1c510(int);
void func_00b1c510()
{
    G4_func_00b1c510(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
