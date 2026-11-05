// roc 2012-06 00b14150  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14150
//
// 00b14150  a15c3ae200           mov eax, dword ptr [0xe23a5c]
// 00b14155  50                   push eax
// 00b14156  e8b9dfe6ff           call 0x982114
// 00b1415b  83c404               add esp, 4
// 00b1415e  c705343ae2002c3cb400 mov dword ptr [0xe23a34], 0xb43c2c
// 00b14168  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b14150(int);
void func_00b14150()
{
    G4_func_00b14150(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
