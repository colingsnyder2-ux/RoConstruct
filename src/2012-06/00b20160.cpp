// roc 2012-06 00b20160  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20160
//
// 00b20160  a1984ee500           mov eax, dword ptr [0xe54e98]
// 00b20165  50                   push eax
// 00b20166  e8a91fe6ff           call 0x982114
// 00b2016b  83c404               add esp, 4
// 00b2016e  c705704ee5002c3cb400 mov dword ptr [0xe54e70], 0xb43c2c
// 00b20178  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20160(int);
void func_00b20160()
{
    G4_func_00b20160(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
