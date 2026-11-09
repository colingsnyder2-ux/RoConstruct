// roc 2012-06 00b11d40  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11d40
//
// 00b11d40  a1108de100           mov eax, dword ptr [0xe18d10]
// 00b11d45  50                   push eax
// 00b11d46  e8c903e7ff           call 0x982114
// 00b11d4b  83c404               add esp, 4
// 00b11d4e  c705e88ce1002c3cb400 mov dword ptr [0xe18ce8], 0xb43c2c
// 00b11d58  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b11d40(int);
void func_00b11d40()
{
    G4_func_00b11d40(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
