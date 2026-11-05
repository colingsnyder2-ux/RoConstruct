// from server: 100% by auto
// roc 2007-08 0042db10  unit: boost::any::_N::?$holder  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042db10
//
// 0042db10  51                   push ecx
// 0042db11  8b542410             mov edx, dword ptr [esp + 0x10]
// 0042db15  56                   push esi
// 0042db16  8b742410             mov esi, dword ptr [esp + 0x10]
// 0042db1a  57                   push edi
// 0042db1b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0042db1f  c644240800           mov byte ptr [esp + 8], 0
// 0042db24  8b442408             mov eax, dword ptr [esp + 8]
// 0042db28  50                   push eax
// 0042db29  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0042db2d  52                   push edx
// 0042db2e  51                   push ecx
// 0042db2f  50                   push eax
// 0042db30  56                   push esi
// 0042db31  57                   push edi
// 0042db32  e8f9feffff           call 0x42da30
// 0042db37  83c418               add esp, 0x18
// 0042db3a  8d04f7               lea eax, [edi + esi*8]
// 0042db3d  5f                   pop edi
// 0042db3e  5e                   pop esi
// 0042db3f  59                   pop ecx
// 0042db40  c20c00               ret 0xc
// standard library vector<pod8> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
