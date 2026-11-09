// roc 2012-06 00b18930  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18930
//
// 00b18930  a1286ce300           mov eax, dword ptr [0xe36c28]
// 00b18935  50                   push eax
// 00b18936  e8d997e6ff           call 0x982114
// 00b1893b  83c404               add esp, 4
// 00b1893e  c705006ce3002c3cb400 mov dword ptr [0xe36c00], 0xb43c2c
// 00b18948  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b18930(int);
void func_00b18930()
{
    G4_func_00b18930(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
