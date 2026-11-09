// roc 2012-06 00b14170  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14170
//
// 00b14170  a1883ae200           mov eax, dword ptr [0xe23a88]
// 00b14175  50                   push eax
// 00b14176  e899dfe6ff           call 0x982114
// 00b1417b  83c404               add esp, 4
// 00b1417e  c705603ae2002c3cb400 mov dword ptr [0xe23a60], 0xb43c2c
// 00b14188  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b14170(int);
void func_00b14170()
{
    G4_func_00b14170(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
