// roc 2012-06 00b1c350  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c350
//
// 00b1c350  a1f4aee400           mov eax, dword ptr [0xe4aef4]
// 00b1c355  50                   push eax
// 00b1c356  e8b95de6ff           call 0x982114
// 00b1c35b  83c404               add esp, 4
// 00b1c35e  c705ccaee4002c3cb400 mov dword ptr [0xe4aecc], 0xb43c2c
// 00b1c368  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1c350(int);
void func_00b1c350()
{
    G4_func_00b1c350(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
