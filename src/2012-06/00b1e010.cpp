// roc 2012-06 00b1e010  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e010
//
// 00b1e010  a1fcfce400           mov eax, dword ptr [0xe4fcfc]
// 00b1e015  50                   push eax
// 00b1e016  e8f940e6ff           call 0x982114
// 00b1e01b  83c404               add esp, 4
// 00b1e01e  c705d4fce4002c3cb400 mov dword ptr [0xe4fcd4], 0xb43c2c
// 00b1e028  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e010(int);
void func_00b1e010()
{
    G4_func_00b1e010(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
