// roc 2012-06 00b11f00  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11f00
//
// 00b11f00  a19c9de100           mov eax, dword ptr [0xe19d9c]
// 00b11f05  50                   push eax
// 00b11f06  e80902e7ff           call 0x982114
// 00b11f0b  83c404               add esp, 4
// 00b11f0e  c705709de1002c3cb400 mov dword ptr [0xe19d70], 0xb43c2c
// 00b11f18  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b11f00(int);
void func_00b11f00()
{
    G4_func_00b11f00(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
