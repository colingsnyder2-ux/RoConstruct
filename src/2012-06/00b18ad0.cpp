// roc 2012-06 00b18ad0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18ad0
//
// 00b18ad0  a13870e300           mov eax, dword ptr [0xe37038]
// 00b18ad5  50                   push eax
// 00b18ad6  e83996e6ff           call 0x982114
// 00b18adb  83c404               add esp, 4
// 00b18ade  c7051070e3002c3cb400 mov dword ptr [0xe37010], 0xb43c2c
// 00b18ae8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b18ad0(int);
void func_00b18ad0()
{
    G4_func_00b18ad0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
