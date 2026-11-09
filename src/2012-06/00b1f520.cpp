// roc 2012-06 00b1f520  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f520
//
// 00b1f520  a1002be500           mov eax, dword ptr [0xe52b00]
// 00b1f525  50                   push eax
// 00b1f526  e8e92be6ff           call 0x982114
// 00b1f52b  83c404               add esp, 4
// 00b1f52e  c705d82ae5002c3cb400 mov dword ptr [0xe52ad8], 0xb43c2c
// 00b1f538  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f520(int);
void func_00b1f520()
{
    G4_func_00b1f520(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
