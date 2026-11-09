// from server: 100% by auto
// roc 2010-06 0096a5d0  unit: Ogre::RbxSceneUpdater  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0096a5d0
//
// 0096a5d0  51                   push ecx
// 0096a5d1  8b542410             mov edx, dword ptr [esp + 0x10]
// 0096a5d5  56                   push esi
// 0096a5d6  8b742410             mov esi, dword ptr [esp + 0x10]
// 0096a5da  57                   push edi
// 0096a5db  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0096a5df  c644240800           mov byte ptr [esp + 8], 0
// 0096a5e4  8b442408             mov eax, dword ptr [esp + 8]
// 0096a5e8  50                   push eax
// 0096a5e9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0096a5ed  52                   push edx
// 0096a5ee  83c108               add ecx, 8
// 0096a5f1  51                   push ecx
// 0096a5f2  50                   push eax
// 0096a5f3  56                   push esi
// 0096a5f4  57                   push edi
// 0096a5f5  e856ffffff           call 0x96a550
// 0096a5fa  8d0c76               lea ecx, [esi + esi*2]
// 0096a5fd  83c418               add esp, 0x18
// 0096a600  8d04cf               lea eax, [edi + ecx*8]
// 0096a603  5f                   pop edi
// 0096a604  5e                   pop esi
// 0096a605  59                   pop ecx
// 0096a606  c20c00               ret 0xc
// standard library vector<pod24> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
