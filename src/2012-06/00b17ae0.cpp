// roc 2012-06 00b17ae0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17ae0
//
// 00b17ae0  a1fc32e300           mov eax, dword ptr [0xe332fc]
// 00b17ae5  50                   push eax
// 00b17ae6  e829a6e6ff           call 0x982114
// 00b17aeb  83c404               add esp, 4
// 00b17aee  c705d032e3002c3cb400 mov dword ptr [0xe332d0], 0xb43c2c
// 00b17af8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b17ae0(int);
void func_00b17ae0()
{
    G4_func_00b17ae0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
