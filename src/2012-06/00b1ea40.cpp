// roc 2012-06 00b1ea40  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ea40
//
// 00b1ea40  a1300ce500           mov eax, dword ptr [0xe50c30]
// 00b1ea45  50                   push eax
// 00b1ea46  e8c936e6ff           call 0x982114
// 00b1ea4b  83c404               add esp, 4
// 00b1ea4e  c705040ce5002c3cb400 mov dword ptr [0xe50c04], 0xb43c2c
// 00b1ea58  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1ea40(int);
void func_00b1ea40()
{
    G4_func_00b1ea40(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
