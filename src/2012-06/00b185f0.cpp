// roc 2012-06 00b185f0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b185f0
//
// 00b185f0  a1f861e300           mov eax, dword ptr [0xe361f8]
// 00b185f5  50                   push eax
// 00b185f6  e8199be6ff           call 0x982114
// 00b185fb  83c404               add esp, 4
// 00b185fe  c705d061e3002c3cb400 mov dword ptr [0xe361d0], 0xb43c2c
// 00b18608  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b185f0(int);
void func_00b185f0()
{
    G4_func_00b185f0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
