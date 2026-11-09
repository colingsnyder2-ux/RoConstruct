// roc 2012-06 00b1ea20  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ea20
//
// 00b1ea20  a11010e500           mov eax, dword ptr [0xe51010]
// 00b1ea25  50                   push eax
// 00b1ea26  e8e936e6ff           call 0x982114
// 00b1ea2b  83c404               add esp, 4
// 00b1ea2e  c705e40fe5002c3cb400 mov dword ptr [0xe50fe4], 0xb43c2c
// 00b1ea38  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1ea20(int);
void func_00b1ea20()
{
    G4_func_00b1ea20(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
