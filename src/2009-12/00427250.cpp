// from server: 100% by auto
// roc 2009-12 00427250  unit: boost::any::H::?$holder  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00427250
//
// 00427250  51                   push ecx
// 00427251  8b542410             mov edx, dword ptr [esp + 0x10]
// 00427255  56                   push esi
// 00427256  8b742410             mov esi, dword ptr [esp + 0x10]
// 0042725a  57                   push edi
// 0042725b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0042725f  c644240800           mov byte ptr [esp + 8], 0
// 00427264  8b442408             mov eax, dword ptr [esp + 8]
// 00427268  50                   push eax
// 00427269  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0042726d  52                   push edx
// 0042726e  83c108               add ecx, 8
// 00427271  51                   push ecx
// 00427272  50                   push eax
// 00427273  56                   push esi
// 00427274  57                   push edi
// 00427275  e876fdffff           call 0x426ff0
// 0042727a  83c418               add esp, 0x18
// 0042727d  8d04f7               lea eax, [edi + esi*8]
// 00427280  5f                   pop edi
// 00427281  5e                   pop esi
// 00427282  59                   pop ecx
// 00427283  c20c00               ret 0xc
// standard library vector<pod8> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
