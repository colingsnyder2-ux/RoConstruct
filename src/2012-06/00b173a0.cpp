// roc 2012-06 00b173a0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b173a0
//
// 00b173a0  a1e817e300           mov eax, dword ptr [0xe317e8]
// 00b173a5  50                   push eax
// 00b173a6  e869ade6ff           call 0x982114
// 00b173ab  83c404               add esp, 4
// 00b173ae  c705c017e3002c3cb400 mov dword ptr [0xe317c0], 0xb43c2c
// 00b173b8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b173a0(int);
void func_00b173a0()
{
    G4_func_00b173a0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
