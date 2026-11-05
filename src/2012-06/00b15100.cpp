// roc 2012-06 00b15100  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15100
//
// 00b15100  a17c97e200           mov eax, dword ptr [0xe2977c]
// 00b15105  50                   push eax
// 00b15106  e809d0e6ff           call 0x982114
// 00b1510b  83c404               add esp, 4
// 00b1510e  c7055497e2002c3cb400 mov dword ptr [0xe29754], 0xb43c2c
// 00b15118  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15100(int);
void func_00b15100()
{
    G4_func_00b15100(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
