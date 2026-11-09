// roc 2012-06 00b17a40  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17a40
//
// 00b17a40  a12c33e300           mov eax, dword ptr [0xe3332c]
// 00b17a45  50                   push eax
// 00b17a46  e8c9a6e6ff           call 0x982114
// 00b17a4b  83c404               add esp, 4
// 00b17a4e  c7050433e3002c3cb400 mov dword ptr [0xe33304], 0xb43c2c
// 00b17a58  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b17a40(int);
void func_00b17a40()
{
    G4_func_00b17a40(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
