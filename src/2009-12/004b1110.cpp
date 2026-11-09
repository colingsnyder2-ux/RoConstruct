// from server: 100% by auto
// roc 2009-12 004b1110  unit: Ogre::RbxTextureCompositorSceneManager  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b1110
//
// 004b1110  51                   push ecx
// 004b1111  8b542410             mov edx, dword ptr [esp + 0x10]
// 004b1115  56                   push esi
// 004b1116  8b742410             mov esi, dword ptr [esp + 0x10]
// 004b111a  57                   push edi
// 004b111b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004b111f  c644240800           mov byte ptr [esp + 8], 0
// 004b1124  8b442408             mov eax, dword ptr [esp + 8]
// 004b1128  50                   push eax
// 004b1129  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004b112d  52                   push edx
// 004b112e  83c108               add ecx, 8
// 004b1131  51                   push ecx
// 004b1132  50                   push eax
// 004b1133  56                   push esi
// 004b1134  57                   push edi
// 004b1135  e836f6ffff           call 0x4b0770
// 004b113a  8bc6                 mov eax, esi
// 004b113c  83c418               add esp, 0x18
// 004b113f  c1e006               shl eax, 6
// 004b1142  03c7                 add eax, edi
// 004b1144  5f                   pop edi
// 004b1145  5e                   pop esi
// 004b1146  59                   pop ecx
// 004b1147  c20c00               ret 0xc
// standard library vector<pod64> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod64>
struct E { int v[16]; };
#include <vector>
template class std::vector<E>;
