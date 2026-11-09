// roc 2012-06 00b20990  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20990
//
// 00b20990  a1385be500           mov eax, dword ptr [0xe55b38]
// 00b20995  50                   push eax
// 00b20996  e87917e6ff           call 0x982114
// 00b2099b  83c404               add esp, 4
// 00b2099e  c7050c5be5002c3cb400 mov dword ptr [0xe55b0c], 0xb43c2c
// 00b209a8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20990(int);
void func_00b20990()
{
    G4_func_00b20990(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
