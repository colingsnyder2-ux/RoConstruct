// roc 2012-06 00b16b00  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16b00
//
// 00b16b00  a1f4f7e200           mov eax, dword ptr [0xe2f7f4]
// 00b16b05  50                   push eax
// 00b16b06  e809b6e6ff           call 0x982114
// 00b16b0b  83c404               add esp, 4
// 00b16b0e  c705c8f7e2002c3cb400 mov dword ptr [0xe2f7c8], 0xb43c2c
// 00b16b18  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b16b00(int);
void func_00b16b00()
{
    G4_func_00b16b00(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
