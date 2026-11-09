// roc 2012-06 00b1c250  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c250
//
// 00b1c250  a148abe400           mov eax, dword ptr [0xe4ab48]
// 00b1c255  50                   push eax
// 00b1c256  e8b95ee6ff           call 0x982114
// 00b1c25b  83c404               add esp, 4
// 00b1c25e  c70520abe4002c3cb400 mov dword ptr [0xe4ab20], 0xb43c2c
// 00b1c268  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1c250(int);
void func_00b1c250()
{
    G4_func_00b1c250(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
