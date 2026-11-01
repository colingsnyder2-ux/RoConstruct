// from server: 100% by auto
// roc 2009-12 00443340  unit: RBX::MergeBinder  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00443340
//
// 00443340  51                   push ecx
// 00443341  8b542410             mov edx, dword ptr [esp + 0x10]
// 00443345  56                   push esi
// 00443346  8b742410             mov esi, dword ptr [esp + 0x10]
// 0044334a  57                   push edi
// 0044334b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0044334f  c644240800           mov byte ptr [esp + 8], 0
// 00443354  8b442408             mov eax, dword ptr [esp + 8]
// 00443358  50                   push eax
// 00443359  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0044335d  52                   push edx
// 0044335e  83c108               add ecx, 8
// 00443361  51                   push ecx
// 00443362  50                   push eax
// 00443363  56                   push esi
// 00443364  57                   push edi
// 00443365  e836ffffff           call 0x4432a0
// 0044336a  8bc6                 mov eax, esi
// 0044336c  83c418               add esp, 0x18
// 0044336f  c1e004               shl eax, 4
// 00443372  03c7                 add eax, edi
// 00443374  5f                   pop edi
// 00443375  5e                   pop esi
// 00443376  59                   pop ecx
// 00443377  c20c00               ret 0xc
// standard library vector<pod16> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
