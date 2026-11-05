// roc 2012-06 00b1c670  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c670
//
// 00b1c670  a1fcb2e400           mov eax, dword ptr [0xe4b2fc]
// 00b1c675  50                   push eax
// 00b1c676  e8995ae6ff           call 0x982114
// 00b1c67b  83c404               add esp, 4
// 00b1c67e  c705d4b2e4002c3cb400 mov dword ptr [0xe4b2d4], 0xb43c2c
// 00b1c688  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1c670(int);
void func_00b1c670()
{
    G4_func_00b1c670(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
