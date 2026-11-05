// from server: 100% by auto
// roc 2008-06 0042d550  unit: boost::any::H::?$holder  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0042d550
//
// 0042d550  51                   push ecx
// 0042d551  8b542410             mov edx, dword ptr [esp + 0x10]
// 0042d555  56                   push esi
// 0042d556  8b742410             mov esi, dword ptr [esp + 0x10]
// 0042d55a  57                   push edi
// 0042d55b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0042d55f  c644240800           mov byte ptr [esp + 8], 0
// 0042d564  8b442408             mov eax, dword ptr [esp + 8]
// 0042d568  50                   push eax
// 0042d569  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0042d56d  52                   push edx
// 0042d56e  83c108               add ecx, 8
// 0042d571  51                   push ecx
// 0042d572  50                   push eax
// 0042d573  56                   push esi
// 0042d574  57                   push edi
// 0042d575  e8f6feffff           call 0x42d470
// 0042d57a  83c418               add esp, 0x18
// 0042d57d  8d04f7               lea eax, [edi + esi*8]
// 0042d580  5f                   pop edi
// 0042d581  5e                   pop esi
// 0042d582  59                   pop ecx
// 0042d583  c20c00               ret 0xc
// standard library vector<pod8> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
