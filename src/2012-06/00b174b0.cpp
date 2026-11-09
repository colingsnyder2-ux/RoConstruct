// roc 2012-06 00b174b0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b174b0
//
// 00b174b0  a1301ae300           mov eax, dword ptr [0xe31a30]
// 00b174b5  50                   push eax
// 00b174b6  e859ace6ff           call 0x982114
// 00b174bb  83c404               add esp, 4
// 00b174be  c705081ae3002c3cb400 mov dword ptr [0xe31a08], 0xb43c2c
// 00b174c8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b174b0(int);
void func_00b174b0()
{
    G4_func_00b174b0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
