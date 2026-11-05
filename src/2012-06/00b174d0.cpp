// roc 2012-06 00b174d0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b174d0
//
// 00b174d0  a1d019e300           mov eax, dword ptr [0xe319d0]
// 00b174d5  50                   push eax
// 00b174d6  e839ace6ff           call 0x982114
// 00b174db  83c404               add esp, 4
// 00b174de  c705a819e3002c3cb400 mov dword ptr [0xe319a8], 0xb43c2c
// 00b174e8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b174d0(int);
void func_00b174d0()
{
    G4_func_00b174d0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
