// roc 2012-06 00b20200  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20200
//
// 00b20200  a1c84fe500           mov eax, dword ptr [0xe54fc8]
// 00b20205  50                   push eax
// 00b20206  e8091fe6ff           call 0x982114
// 00b2020b  83c404               add esp, 4
// 00b2020e  c705a04fe5002c3cb400 mov dword ptr [0xe54fa0], 0xb43c2c
// 00b20218  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20200(int);
void func_00b20200()
{
    G4_func_00b20200(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
