// roc 2012-06 00b20410  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20410
//
// 00b20410  a15452e500           mov eax, dword ptr [0xe55254]
// 00b20415  50                   push eax
// 00b20416  e8f91ce6ff           call 0x982114
// 00b2041b  83c404               add esp, 4
// 00b2041e  c7052c52e5002c3cb400 mov dword ptr [0xe5522c], 0xb43c2c
// 00b20428  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20410(int);
void func_00b20410()
{
    G4_func_00b20410(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
