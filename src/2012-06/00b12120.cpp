// roc 2012-06 00b12120  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12120
//
// 00b12120  a1a49ce100           mov eax, dword ptr [0xe19ca4]
// 00b12125  50                   push eax
// 00b12126  e8e9ffe6ff           call 0x982114
// 00b1212b  83c404               add esp, 4
// 00b1212e  c7057c9ce1002c3cb400 mov dword ptr [0xe19c7c], 0xb43c2c
// 00b12138  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b12120(int);
void func_00b12120()
{
    G4_func_00b12120(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
