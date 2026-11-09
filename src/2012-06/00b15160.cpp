// roc 2012-06 00b15160  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15160
//
// 00b15160  a14c96e200           mov eax, dword ptr [0xe2964c]
// 00b15165  50                   push eax
// 00b15166  e8a9cfe6ff           call 0x982114
// 00b1516b  83c404               add esp, 4
// 00b1516e  c7052496e2002c3cb400 mov dword ptr [0xe29624], 0xb43c2c
// 00b15178  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15160(int);
void func_00b15160()
{
    G4_func_00b15160(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
