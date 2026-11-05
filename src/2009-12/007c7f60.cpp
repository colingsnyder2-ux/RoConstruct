// from server: 100% by auto
// roc 2009-12 007c7f60  unit: RBX::ScoreHud  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c7f60
//
// 007c7f60  51                   push ecx
// 007c7f61  8b542410             mov edx, dword ptr [esp + 0x10]
// 007c7f65  56                   push esi
// 007c7f66  8b742410             mov esi, dword ptr [esp + 0x10]
// 007c7f6a  57                   push edi
// 007c7f6b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007c7f6f  c644240800           mov byte ptr [esp + 8], 0
// 007c7f74  8b442408             mov eax, dword ptr [esp + 8]
// 007c7f78  50                   push eax
// 007c7f79  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007c7f7d  52                   push edx
// 007c7f7e  83c108               add ecx, 8
// 007c7f81  51                   push ecx
// 007c7f82  50                   push eax
// 007c7f83  56                   push esi
// 007c7f84  57                   push edi
// 007c7f85  e8f6f0ffff           call 0x7c7080
// 007c7f8a  8d0c76               lea ecx, [esi + esi*2]
// 007c7f8d  83c418               add esp, 0x18
// 007c7f90  8d04cf               lea eax, [edi + ecx*8]
// 007c7f93  5f                   pop edi
// 007c7f94  5e                   pop esi
// 007c7f95  59                   pop ecx
// 007c7f96  c20c00               ret 0xc
// standard library vector<pod24> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
