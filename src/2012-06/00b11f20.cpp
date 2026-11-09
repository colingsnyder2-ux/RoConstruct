// roc 2012-06 00b11f20  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11f20
//
// 00b11f20  a1d49ae100           mov eax, dword ptr [0xe19ad4]
// 00b11f25  50                   push eax
// 00b11f26  e8e901e7ff           call 0x982114
// 00b11f2b  83c404               add esp, 4
// 00b11f2e  c705a89ae1002c3cb400 mov dword ptr [0xe19aa8], 0xb43c2c
// 00b11f38  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b11f20(int);
void func_00b11f20()
{
    G4_func_00b11f20(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
