// roc 2012-06 00b209d0  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b209d0
//
// 00b209d0  a1a45be500           mov eax, dword ptr [0xe55ba4]
// 00b209d5  50                   push eax
// 00b209d6  e83917e6ff           call 0x982114
// 00b209db  83c404               add esp, 4
// 00b209de  c705785be5002c3cb400 mov dword ptr [0xe55b78], 0xb43c2c
// 00b209e8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b209d0(int);
void func_00b209d0()
{
    G4_func_00b209d0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
