// roc 2012-06 00b17cc0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17cc0
//
// 00b17cc0  a1543ae300           mov eax, dword ptr [0xe33a54]
// 00b17cc5  50                   push eax
// 00b17cc6  e849a4e6ff           call 0x982114
// 00b17ccb  83c404               add esp, 4
// 00b17cce  c7052c3ae3002c3cb400 mov dword ptr [0xe33a2c], 0xb43c2c
// 00b17cd8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b17cc0(int);
void func_00b17cc0()
{
    G4_func_00b17cc0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
