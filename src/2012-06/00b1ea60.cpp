// roc 2012-06 00b1ea60  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ea60
//
// 00b1ea60  a1300fe500           mov eax, dword ptr [0xe50f30]
// 00b1ea65  50                   push eax
// 00b1ea66  e8a936e6ff           call 0x982114
// 00b1ea6b  83c404               add esp, 4
// 00b1ea6e  c705080fe5002c3cb400 mov dword ptr [0xe50f08], 0xb43c2c
// 00b1ea78  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1ea60(int);
void func_00b1ea60()
{
    G4_func_00b1ea60(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
