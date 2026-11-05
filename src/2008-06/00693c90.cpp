// from server: 100% by auto
// roc 2008-06 00693c90  unit: Ogre::RbxSceneManager  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00693c90
//
// 00693c90  51                   push ecx
// 00693c91  8b542410             mov edx, dword ptr [esp + 0x10]
// 00693c95  56                   push esi
// 00693c96  8b742410             mov esi, dword ptr [esp + 0x10]
// 00693c9a  57                   push edi
// 00693c9b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00693c9f  c644240800           mov byte ptr [esp + 8], 0
// 00693ca4  8b442408             mov eax, dword ptr [esp + 8]
// 00693ca8  50                   push eax
// 00693ca9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00693cad  52                   push edx
// 00693cae  83c108               add ecx, 8
// 00693cb1  51                   push ecx
// 00693cb2  50                   push eax
// 00693cb3  56                   push esi
// 00693cb4  57                   push edi
// 00693cb5  e896c5ffff           call 0x690250
// 00693cba  8d0c76               lea ecx, [esi + esi*2]
// 00693cbd  83c418               add esp, 0x18
// 00693cc0  8d04cf               lea eax, [edi + ecx*8]
// 00693cc3  5f                   pop edi
// 00693cc4  5e                   pop esi
// 00693cc5  59                   pop ecx
// 00693cc6  c20c00               ret 0xc
// standard library vector<pod24> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
