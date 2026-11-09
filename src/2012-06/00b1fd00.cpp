// roc 2012-06 00b1fd00  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1fd00
//
// 00b1fd00  a1603ae500           mov eax, dword ptr [0xe53a60]
// 00b1fd05  50                   push eax
// 00b1fd06  e80924e6ff           call 0x982114
// 00b1fd0b  83c404               add esp, 4
// 00b1fd0e  c705343ae5002c3cb400 mov dword ptr [0xe53a34], 0xb43c2c
// 00b1fd18  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1fd00(int);
void func_00b1fd00()
{
    G4_func_00b1fd00(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
