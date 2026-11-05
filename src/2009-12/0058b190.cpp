// from server: 100% by auto
// roc 2009-12 0058b190  unit: RBX::BeveledBlockBuilder  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0058b190
//
// 0058b190  51                   push ecx
// 0058b191  8b542410             mov edx, dword ptr [esp + 0x10]
// 0058b195  56                   push esi
// 0058b196  8b742410             mov esi, dword ptr [esp + 0x10]
// 0058b19a  57                   push edi
// 0058b19b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0058b19f  c644240800           mov byte ptr [esp + 8], 0
// 0058b1a4  8b442408             mov eax, dword ptr [esp + 8]
// 0058b1a8  50                   push eax
// 0058b1a9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0058b1ad  52                   push edx
// 0058b1ae  83c108               add ecx, 8
// 0058b1b1  51                   push ecx
// 0058b1b2  50                   push eax
// 0058b1b3  56                   push esi
// 0058b1b4  57                   push edi
// 0058b1b5  e806ffffff           call 0x58b0c0
// 0058b1ba  8d0c76               lea ecx, [esi + esi*2]
// 0058b1bd  83c418               add esp, 0x18
// 0058b1c0  8d04cf               lea eax, [edi + ecx*8]
// 0058b1c3  5f                   pop edi
// 0058b1c4  5e                   pop esi
// 0058b1c5  59                   pop ecx
// 0058b1c6  c20c00               ret 0xc
// standard library vector<pod24> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
