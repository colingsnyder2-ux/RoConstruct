// roc 2012-06 00b200e0  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b200e0
//
// 00b200e0  a13c4ae500           mov eax, dword ptr [0xe54a3c]
// 00b200e5  50                   push eax
// 00b200e6  e82920e6ff           call 0x982114
// 00b200eb  83c404               add esp, 4
// 00b200ee  c705144ae5002c3cb400 mov dword ptr [0xe54a14], 0xb43c2c
// 00b200f8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b200e0(int);
void func_00b200e0()
{
    G4_func_00b200e0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
