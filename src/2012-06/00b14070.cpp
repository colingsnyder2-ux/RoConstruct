// roc 2012-06 00b14070  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14070
//
// 00b14070  a1583ce200           mov eax, dword ptr [0xe23c58]
// 00b14075  50                   push eax
// 00b14076  e899e0e6ff           call 0x982114
// 00b1407b  83c404               add esp, 4
// 00b1407e  c705303ce2002c3cb400 mov dword ptr [0xe23c30], 0xb43c2c
// 00b14088  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b14070(int);
void func_00b14070()
{
    G4_func_00b14070(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
