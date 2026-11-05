// roc 2012-06 00b18a90  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18a90
//
// 00b18a90  a1886fe300           mov eax, dword ptr [0xe36f88]
// 00b18a95  50                   push eax
// 00b18a96  e87996e6ff           call 0x982114
// 00b18a9b  83c404               add esp, 4
// 00b18a9e  c705606fe3002c3cb400 mov dword ptr [0xe36f60], 0xb43c2c
// 00b18aa8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b18a90(int);
void func_00b18a90()
{
    G4_func_00b18a90(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
