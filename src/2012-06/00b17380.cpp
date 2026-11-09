// roc 2012-06 00b17380  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17380
//
// 00b17380  a12817e300           mov eax, dword ptr [0xe31728]
// 00b17385  50                   push eax
// 00b17386  e889ade6ff           call 0x982114
// 00b1738b  83c404               add esp, 4
// 00b1738e  c7050017e3002c3cb400 mov dword ptr [0xe31700], 0xb43c2c
// 00b17398  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b17380(int);
void func_00b17380()
{
    G4_func_00b17380(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
