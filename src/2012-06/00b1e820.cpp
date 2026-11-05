// roc 2012-06 00b1e820  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e820
//
// 00b1e820  a1840be500           mov eax, dword ptr [0xe50b84]
// 00b1e825  50                   push eax
// 00b1e826  e8e938e6ff           call 0x982114
// 00b1e82b  83c404               add esp, 4
// 00b1e82e  c705580be5002c3cb400 mov dword ptr [0xe50b58], 0xb43c2c
// 00b1e838  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e820(int);
void func_00b1e820()
{
    G4_func_00b1e820(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
