// roc 2012-06 00b20950  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20950
//
// 00b20950  a16c5ae500           mov eax, dword ptr [0xe55a6c]
// 00b20955  50                   push eax
// 00b20956  e8b917e6ff           call 0x982114
// 00b2095b  83c404               add esp, 4
// 00b2095e  c705445ae5002c3cb400 mov dword ptr [0xe55a44], 0xb43c2c
// 00b20968  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20950(int);
void func_00b20950()
{
    G4_func_00b20950(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
