// roc 2012-06 00b1f990  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f990
//
// 00b1f990  a1ec32e500           mov eax, dword ptr [0xe532ec]
// 00b1f995  50                   push eax
// 00b1f996  e87927e6ff           call 0x982114
// 00b1f99b  83c404               add esp, 4
// 00b1f99e  c705c432e5002c3cb400 mov dword ptr [0xe532c4], 0xb43c2c
// 00b1f9a8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f990(int);
void func_00b1f990()
{
    G4_func_00b1f990(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
