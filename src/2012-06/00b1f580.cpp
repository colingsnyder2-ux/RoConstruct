// roc 2012-06 00b1f580  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f580
//
// 00b1f580  a1fc28e500           mov eax, dword ptr [0xe528fc]
// 00b1f585  50                   push eax
// 00b1f586  e8892be6ff           call 0x982114
// 00b1f58b  83c404               add esp, 4
// 00b1f58e  c705d428e5002c3cb400 mov dword ptr [0xe528d4], 0xb43c2c
// 00b1f598  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f580(int);
void func_00b1f580()
{
    G4_func_00b1f580(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
