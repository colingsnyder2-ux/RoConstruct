// roc 2012-06 00b13900  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13900
//
// 00b13900  a1c01de200           mov eax, dword ptr [0xe21dc0]
// 00b13905  50                   push eax
// 00b13906  e809e8e6ff           call 0x982114
// 00b1390b  83c404               add esp, 4
// 00b1390e  c705981de2002c3cb400 mov dword ptr [0xe21d98], 0xb43c2c
// 00b13918  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b13900(int);
void func_00b13900()
{
    G4_func_00b13900(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
