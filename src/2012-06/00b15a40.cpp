// roc 2012-06 00b15a40  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15a40
//
// 00b15a40  a1bcb0e200           mov eax, dword ptr [0xe2b0bc]
// 00b15a45  50                   push eax
// 00b15a46  e8c9c6e6ff           call 0x982114
// 00b15a4b  83c404               add esp, 4
// 00b15a4e  c70594b0e2002c3cb400 mov dword ptr [0xe2b094], 0xb43c2c
// 00b15a58  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15a40(int);
void func_00b15a40()
{
    G4_func_00b15a40(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
