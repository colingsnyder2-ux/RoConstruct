// roc 2012-06 00b15560  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15560
//
// 00b15560  a1a496e200           mov eax, dword ptr [0xe296a4]
// 00b15565  50                   push eax
// 00b15566  e8a9cbe6ff           call 0x982114
// 00b1556b  83c404               add esp, 4
// 00b1556e  c7057c96e2002c3cb400 mov dword ptr [0xe2967c], 0xb43c2c
// 00b15578  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15560(int);
void func_00b15560()
{
    G4_func_00b15560(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
