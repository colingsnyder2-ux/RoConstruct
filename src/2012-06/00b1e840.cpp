// roc 2012-06 00b1e840  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e840
//
// 00b1e840  a17c0ee500           mov eax, dword ptr [0xe50e7c]
// 00b1e845  50                   push eax
// 00b1e846  e8c938e6ff           call 0x982114
// 00b1e84b  83c404               add esp, 4
// 00b1e84e  c705500ee5002c3cb400 mov dword ptr [0xe50e50], 0xb43c2c
// 00b1e858  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e840(int);
void func_00b1e840()
{
    G4_func_00b1e840(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
