// roc 2012-06 00b200c0  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b200c0
//
// 00b200c0  a1684ae500           mov eax, dword ptr [0xe54a68]
// 00b200c5  50                   push eax
// 00b200c6  e84920e6ff           call 0x982114
// 00b200cb  83c404               add esp, 4
// 00b200ce  c705404ae5002c3cb400 mov dword ptr [0xe54a40], 0xb43c2c
// 00b200d8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b200c0(int);
void func_00b200c0()
{
    G4_func_00b200c0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
