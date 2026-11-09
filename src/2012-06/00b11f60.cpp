// roc 2012-06 00b11f60  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11f60
//
// 00b11f60  a1149ae100           mov eax, dword ptr [0xe19a14]
// 00b11f65  50                   push eax
// 00b11f66  e8a901e7ff           call 0x982114
// 00b11f6b  83c404               add esp, 4
// 00b11f6e  c705e899e1002c3cb400 mov dword ptr [0xe199e8], 0xb43c2c
// 00b11f78  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b11f60(int);
void func_00b11f60()
{
    G4_func_00b11f60(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
