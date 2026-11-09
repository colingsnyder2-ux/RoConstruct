// roc 2012-06 00b17530  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17530
//
// 00b17530  a1041ae300           mov eax, dword ptr [0xe31a04]
// 00b17535  50                   push eax
// 00b17536  e8d9abe6ff           call 0x982114
// 00b1753b  83c404               add esp, 4
// 00b1753e  c705dc19e3002c3cb400 mov dword ptr [0xe319dc], 0xb43c2c
// 00b17548  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b17530(int);
void func_00b17530()
{
    G4_func_00b17530(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
