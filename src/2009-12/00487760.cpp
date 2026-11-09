// from server: 100% by auto
// roc 2009-12 00487760  unit: Ogre::GfxClustererPart  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00487760
//
// 00487760  51                   push ecx
// 00487761  8b542410             mov edx, dword ptr [esp + 0x10]
// 00487765  56                   push esi
// 00487766  8b742410             mov esi, dword ptr [esp + 0x10]
// 0048776a  57                   push edi
// 0048776b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0048776f  c644240800           mov byte ptr [esp + 8], 0
// 00487774  8b442408             mov eax, dword ptr [esp + 8]
// 00487778  50                   push eax
// 00487779  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0048777d  52                   push edx
// 0048777e  83c108               add ecx, 8
// 00487781  51                   push ecx
// 00487782  50                   push eax
// 00487783  56                   push esi
// 00487784  57                   push edi
// 00487785  e816f1ffff           call 0x4868a0
// 0048778a  8bc6                 mov eax, esi
// 0048778c  83c418               add esp, 0x18
// 0048778f  c1e005               shl eax, 5
// 00487792  03c7                 add eax, edi
// 00487794  5f                   pop edi
// 00487795  5e                   pop esi
// 00487796  59                   pop ecx
// 00487797  c20c00               ret 0xc
// standard library vector<pod32> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;
