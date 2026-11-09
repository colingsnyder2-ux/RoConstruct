// roc 2012-06 00b12380  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12380
//
// 00b12380  a17c99e100           mov eax, dword ptr [0xe1997c]
// 00b12385  50                   push eax
// 00b12386  e889fde6ff           call 0x982114
// 00b1238b  83c404               add esp, 4
// 00b1238e  c7055499e1002c3cb400 mov dword ptr [0xe19954], 0xb43c2c
// 00b12398  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b12380(int);
void func_00b12380()
{
    G4_func_00b12380(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
