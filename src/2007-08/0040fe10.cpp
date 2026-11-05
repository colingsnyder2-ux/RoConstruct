// from server: 100% by auto
// roc 2007-08 0040fe10  unit: CopyVerb  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040fe10
//
// 0040fe10  51                   push ecx
// 0040fe11  8b542410             mov edx, dword ptr [esp + 0x10]
// 0040fe15  56                   push esi
// 0040fe16  8b742410             mov esi, dword ptr [esp + 0x10]
// 0040fe1a  57                   push edi
// 0040fe1b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0040fe1f  c644240800           mov byte ptr [esp + 8], 0
// 0040fe24  8b442408             mov eax, dword ptr [esp + 8]
// 0040fe28  50                   push eax
// 0040fe29  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0040fe2d  52                   push edx
// 0040fe2e  51                   push ecx
// 0040fe2f  50                   push eax
// 0040fe30  56                   push esi
// 0040fe31  57                   push edi
// 0040fe32  e8a9fdffff           call 0x40fbe0
// 0040fe37  8d0cf6               lea ecx, [esi + esi*8]
// 0040fe3a  83c418               add esp, 0x18
// 0040fe3d  8d048f               lea eax, [edi + ecx*4]
// 0040fe40  5f                   pop edi
// 0040fe41  5e                   pop esi
// 0040fe42  59                   pop ecx
// 0040fe43  c20c00               ret 0xc
// standard library vector<pod36> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod36>
struct E { int v[9]; };
#include <vector>
template class std::vector<E>;
