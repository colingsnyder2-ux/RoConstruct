// from server: 100% by auto
// roc 2009-12 00480630  unit: RBX::AdornRbxGfx  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00480630
//
// 00480630  51                   push ecx
// 00480631  8b542410             mov edx, dword ptr [esp + 0x10]
// 00480635  56                   push esi
// 00480636  8b742410             mov esi, dword ptr [esp + 0x10]
// 0048063a  57                   push edi
// 0048063b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0048063f  c644240800           mov byte ptr [esp + 8], 0
// 00480644  8b442408             mov eax, dword ptr [esp + 8]
// 00480648  50                   push eax
// 00480649  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0048064d  52                   push edx
// 0048064e  83c108               add ecx, 8
// 00480651  51                   push ecx
// 00480652  50                   push eax
// 00480653  56                   push esi
// 00480654  57                   push edi
// 00480655  e8a6efffff           call 0x47f600
// 0048065a  83c418               add esp, 0x18
// 0048065d  8d04f7               lea eax, [edi + esi*8]
// 00480660  5f                   pop edi
// 00480661  5e                   pop esi
// 00480662  59                   pop ecx
// 00480663  c20c00               ret 0xc
// standard library vector<pod8> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
