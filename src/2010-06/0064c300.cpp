// from server: 100% by auto
// roc 2010-06 0064c300  unit: RBX::VWidget::?$NonFactoryProduct  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0064c300
//
// 0064c300  51                   push ecx
// 0064c301  8b542410             mov edx, dword ptr [esp + 0x10]
// 0064c305  56                   push esi
// 0064c306  8b742410             mov esi, dword ptr [esp + 0x10]
// 0064c30a  57                   push edi
// 0064c30b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0064c30f  c644240800           mov byte ptr [esp + 8], 0
// 0064c314  8b442408             mov eax, dword ptr [esp + 8]
// 0064c318  50                   push eax
// 0064c319  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0064c31d  52                   push edx
// 0064c31e  83c108               add ecx, 8
// 0064c321  51                   push ecx
// 0064c322  50                   push eax
// 0064c323  56                   push esi
// 0064c324  57                   push edi
// 0064c325  e8c6b30000           call 0x6576f0
// 0064c32a  83c418               add esp, 0x18
// 0064c32d  8d04f7               lea eax, [edi + esi*8]
// 0064c330  5f                   pop edi
// 0064c331  5e                   pop esi
// 0064c332  59                   pop ecx
// 0064c333  c20c00               ret 0xc
// standard library vector<pod8> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
