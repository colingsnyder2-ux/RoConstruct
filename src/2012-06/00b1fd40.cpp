// roc 2012-06 00b1fd40  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1fd40
//
// 00b1fd40  a1103be500           mov eax, dword ptr [0xe53b10]
// 00b1fd45  50                   push eax
// 00b1fd46  e8c923e6ff           call 0x982114
// 00b1fd4b  83c404               add esp, 4
// 00b1fd4e  c705e83ae5002c3cb400 mov dword ptr [0xe53ae8], 0xb43c2c
// 00b1fd58  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1fd40(int);
void func_00b1fd40()
{
    G4_func_00b1fd40(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
