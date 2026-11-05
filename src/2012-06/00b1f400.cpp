// roc 2012-06 00b1f400  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f400
//
// 00b1f400  a1d42ae500           mov eax, dword ptr [0xe52ad4]
// 00b1f405  50                   push eax
// 00b1f406  e8092de6ff           call 0x982114
// 00b1f40b  83c404               add esp, 4
// 00b1f40e  c705ac2ae5002c3cb400 mov dword ptr [0xe52aac], 0xb43c2c
// 00b1f418  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f400(int);
void func_00b1f400()
{
    G4_func_00b1f400(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
