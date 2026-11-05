// roc 2012-06 00b16b40  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16b40
//
// 00b16b40  a134ede200           mov eax, dword ptr [0xe2ed34]
// 00b16b45  50                   push eax
// 00b16b46  e8c9b5e6ff           call 0x982114
// 00b16b4b  83c404               add esp, 4
// 00b16b4e  c70508ede2002c3cb400 mov dword ptr [0xe2ed08], 0xb43c2c
// 00b16b58  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b16b40(int);
void func_00b16b40()
{
    G4_func_00b16b40(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
