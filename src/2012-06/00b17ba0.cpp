// roc 2012-06 00b17ba0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17ba0
//
// 00b17ba0  a1a032e300           mov eax, dword ptr [0xe332a0]
// 00b17ba5  50                   push eax
// 00b17ba6  e869a5e6ff           call 0x982114
// 00b17bab  83c404               add esp, 4
// 00b17bae  c7057832e3002c3cb400 mov dword ptr [0xe33278], 0xb43c2c
// 00b17bb8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b17ba0(int);
void func_00b17ba0()
{
    G4_func_00b17ba0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
