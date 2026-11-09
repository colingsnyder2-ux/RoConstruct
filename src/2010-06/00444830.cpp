// from server: 100% by auto
// roc 2010-06 00444830  unit: RBX::MergeBinder  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00444830
//
// 00444830  51                   push ecx
// 00444831  8b542410             mov edx, dword ptr [esp + 0x10]
// 00444835  56                   push esi
// 00444836  8b742410             mov esi, dword ptr [esp + 0x10]
// 0044483a  57                   push edi
// 0044483b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0044483f  c644240800           mov byte ptr [esp + 8], 0
// 00444844  8b442408             mov eax, dword ptr [esp + 8]
// 00444848  50                   push eax
// 00444849  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0044484d  52                   push edx
// 0044484e  83c108               add ecx, 8
// 00444851  51                   push ecx
// 00444852  50                   push eax
// 00444853  56                   push esi
// 00444854  57                   push edi
// 00444855  e836ffffff           call 0x444790
// 0044485a  8bc6                 mov eax, esi
// 0044485c  83c418               add esp, 0x18
// 0044485f  c1e004               shl eax, 4
// 00444862  03c7                 add eax, edi
// 00444864  5f                   pop edi
// 00444865  5e                   pop esi
// 00444866  59                   pop ecx
// 00444867  c20c00               ret 0xc
// standard library vector<pod16> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
