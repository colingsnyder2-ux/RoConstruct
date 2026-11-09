// roc 2012-06 00b12160  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12160
//
// 00b12160  a1789ae100           mov eax, dword ptr [0xe19a78]
// 00b12165  50                   push eax
// 00b12166  e8a9ffe6ff           call 0x982114
// 00b1216b  83c404               add esp, 4
// 00b1216e  c705509ae1002c3cb400 mov dword ptr [0xe19a50], 0xb43c2c
// 00b12178  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b12160(int);
void func_00b12160()
{
    G4_func_00b12160(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
