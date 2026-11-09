// from server: 100% by auto
// roc 2008-06 00412140  unit: CChatPrompt  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00412140
//
// 00412140  51                   push ecx
// 00412141  8b542410             mov edx, dword ptr [esp + 0x10]
// 00412145  56                   push esi
// 00412146  8b742410             mov esi, dword ptr [esp + 0x10]
// 0041214a  57                   push edi
// 0041214b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0041214f  c644240800           mov byte ptr [esp + 8], 0
// 00412154  8b442408             mov eax, dword ptr [esp + 8]
// 00412158  50                   push eax
// 00412159  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0041215d  52                   push edx
// 0041215e  83c108               add ecx, 8
// 00412161  51                   push ecx
// 00412162  50                   push eax
// 00412163  56                   push esi
// 00412164  57                   push edi
// 00412165  e896ffffff           call 0x412100
// 0041216a  83c418               add esp, 0x18
// 0041216d  8d04f7               lea eax, [edi + esi*8]
// 00412170  5f                   pop edi
// 00412171  5e                   pop esi
// 00412172  59                   pop ecx
// 00412173  c20c00               ret 0xc
// standard library vector<pod8> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
