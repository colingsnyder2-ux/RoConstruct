// roc 2012-06 00b13fd0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13fd0
//
// 00b13fd0  a16c39e200           mov eax, dword ptr [0xe2396c]
// 00b13fd5  50                   push eax
// 00b13fd6  e839e1e6ff           call 0x982114
// 00b13fdb  83c404               add esp, 4
// 00b13fde  c7054439e2002c3cb400 mov dword ptr [0xe23944], 0xb43c2c
// 00b13fe8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b13fd0(int);
void func_00b13fd0()
{
    G4_func_00b13fd0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
