// roc 2012-06 00b14210  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14210
//
// 00b14210  a16438e200           mov eax, dword ptr [0xe23864]
// 00b14215  50                   push eax
// 00b14216  e8f9dee6ff           call 0x982114
// 00b1421b  83c404               add esp, 4
// 00b1421e  c7053c38e2002c3cb400 mov dword ptr [0xe2383c], 0xb43c2c
// 00b14228  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b14210(int);
void func_00b14210()
{
    G4_func_00b14210(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
