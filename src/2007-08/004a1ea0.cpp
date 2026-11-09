// from server: 100% by auto
// roc 2007-08 004a1ea0  unit: RBX::Network::VServer::?$BoundFuncDesc  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a1ea0
//
// 004a1ea0  51                   push ecx
// 004a1ea1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a1ea5  56                   push esi
// 004a1ea6  8b742410             mov esi, dword ptr [esp + 0x10]
// 004a1eaa  57                   push edi
// 004a1eab  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004a1eaf  c644240800           mov byte ptr [esp + 8], 0
// 004a1eb4  8b442408             mov eax, dword ptr [esp + 8]
// 004a1eb8  50                   push eax
// 004a1eb9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004a1ebd  52                   push edx
// 004a1ebe  51                   push ecx
// 004a1ebf  50                   push eax
// 004a1ec0  56                   push esi
// 004a1ec1  57                   push edi
// 004a1ec2  e889fcffff           call 0x4a1b50
// 004a1ec7  8d0c76               lea ecx, [esi + esi*2]
// 004a1eca  83c418               add esp, 0x18
// 004a1ecd  8d048f               lea eax, [edi + ecx*4]
// 004a1ed0  5f                   pop edi
// 004a1ed1  5e                   pop esi
// 004a1ed2  59                   pop ecx
// 004a1ed3  c20c00               ret 0xc
// standard library vector<pod12> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
