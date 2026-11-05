// roc 2012-06 00b18950  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18950
//
// 00b18950  a1546ce300           mov eax, dword ptr [0xe36c54]
// 00b18955  50                   push eax
// 00b18956  e8b997e6ff           call 0x982114
// 00b1895b  83c404               add esp, 4
// 00b1895e  c7052c6ce3002c3cb400 mov dword ptr [0xe36c2c], 0xb43c2c
// 00b18968  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b18950(int);
void func_00b18950()
{
    G4_func_00b18950(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
