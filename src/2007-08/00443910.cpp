// from server: 100% by auto
// roc 2007-08 00443910  unit: RBX::MergeBinder  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00443910
//
// 00443910  51                   push ecx
// 00443911  8b542410             mov edx, dword ptr [esp + 0x10]
// 00443915  56                   push esi
// 00443916  8b742410             mov esi, dword ptr [esp + 0x10]
// 0044391a  57                   push edi
// 0044391b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0044391f  c644240800           mov byte ptr [esp + 8], 0
// 00443924  8b442408             mov eax, dword ptr [esp + 8]
// 00443928  50                   push eax
// 00443929  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0044392d  52                   push edx
// 0044392e  51                   push ecx
// 0044392f  50                   push eax
// 00443930  56                   push esi
// 00443931  57                   push edi
// 00443932  e8c9fdffff           call 0x443700
// 00443937  8bc6                 mov eax, esi
// 00443939  83c418               add esp, 0x18
// 0044393c  c1e004               shl eax, 4
// 0044393f  03c7                 add eax, edi
// 00443941  5f                   pop edi
// 00443942  5e                   pop esi
// 00443943  59                   pop ecx
// 00443944  c20c00               ret 0xc
// standard library vector<pod16> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
