// from server: 100% by auto
// roc 2009-06 004867b0  unit: Ogre::RbxMeshPartAdapter  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004867b0
//
// 004867b0  51                   push ecx
// 004867b1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004867b5  56                   push esi
// 004867b6  8b742410             mov esi, dword ptr [esp + 0x10]
// 004867ba  57                   push edi
// 004867bb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004867bf  c644240800           mov byte ptr [esp + 8], 0
// 004867c4  8b442408             mov eax, dword ptr [esp + 8]
// 004867c8  50                   push eax
// 004867c9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004867cd  52                   push edx
// 004867ce  83c108               add ecx, 8
// 004867d1  51                   push ecx
// 004867d2  50                   push eax
// 004867d3  56                   push esi
// 004867d4  57                   push edi
// 004867d5  e886fcffff           call 0x486460
// 004867da  8bc6                 mov eax, esi
// 004867dc  83c418               add esp, 0x18
// 004867df  c1e004               shl eax, 4
// 004867e2  03c7                 add eax, edi
// 004867e4  5f                   pop edi
// 004867e5  5e                   pop esi
// 004867e6  59                   pop ecx
// 004867e7  c20c00               ret 0xc
// standard library vector<pod16> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
