// roc 2012-06 00b18660  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18660
//
// 00b18660  a1f863e300           mov eax, dword ptr [0xe363f8]
// 00b18665  50                   push eax
// 00b18666  e8a99ae6ff           call 0x982114
// 00b1866b  83c404               add esp, 4
// 00b1866e  c705d063e3002c3cb400 mov dword ptr [0xe363d0], 0xb43c2c
// 00b18678  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b18660(int);
void func_00b18660()
{
    G4_func_00b18660(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
