// roc 2012-06 00b13070  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13070
//
// 00b13070  a19c0ee200           mov eax, dword ptr [0xe20e9c]
// 00b13075  50                   push eax
// 00b13076  e899f0e6ff           call 0x982114
// 00b1307b  83c404               add esp, 4
// 00b1307e  c705740ee2002c3cb400 mov dword ptr [0xe20e74], 0xb43c2c
// 00b13088  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b13070(int);
void func_00b13070()
{
    G4_func_00b13070(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
