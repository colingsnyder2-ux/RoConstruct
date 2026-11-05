// roc 2012-06 00b1ee90  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ee90
//
// 00b1ee90  a1241ce500           mov eax, dword ptr [0xe51c24]
// 00b1ee95  50                   push eax
// 00b1ee96  e87932e6ff           call 0x982114
// 00b1ee9b  83c404               add esp, 4
// 00b1ee9e  c705fc1be5002c3cb400 mov dword ptr [0xe51bfc], 0xb43c2c
// 00b1eea8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1ee90(int);
void func_00b1ee90()
{
    G4_func_00b1ee90(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
