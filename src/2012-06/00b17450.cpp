// roc 2012-06 00b17450  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17450
//
// 00b17450  a1a419e300           mov eax, dword ptr [0xe319a4]
// 00b17455  50                   push eax
// 00b17456  e8b9ace6ff           call 0x982114
// 00b1745b  83c404               add esp, 4
// 00b1745e  c7057c19e3002c3cb400 mov dword ptr [0xe3197c], 0xb43c2c
// 00b17468  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b17450(int);
void func_00b17450()
{
    G4_func_00b17450(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
