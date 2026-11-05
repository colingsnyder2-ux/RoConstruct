// from server: 100% by auto
// roc 2008-06 00693eb0  unit: Ogre::RbxSceneManager  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00693eb0
//
// 00693eb0  51                   push ecx
// 00693eb1  8b542410             mov edx, dword ptr [esp + 0x10]
// 00693eb5  56                   push esi
// 00693eb6  8b742410             mov esi, dword ptr [esp + 0x10]
// 00693eba  57                   push edi
// 00693ebb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00693ebf  c644240800           mov byte ptr [esp + 8], 0
// 00693ec4  8b442408             mov eax, dword ptr [esp + 8]
// 00693ec8  50                   push eax
// 00693ec9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00693ecd  52                   push edx
// 00693ece  83c108               add ecx, 8
// 00693ed1  51                   push ecx
// 00693ed2  50                   push eax
// 00693ed3  56                   push esi
// 00693ed4  57                   push edi
// 00693ed5  e8c6c3ffff           call 0x6902a0
// 00693eda  8d0c76               lea ecx, [esi + esi*2]
// 00693edd  83c418               add esp, 0x18
// 00693ee0  8d048f               lea eax, [edi + ecx*4]
// 00693ee3  5f                   pop edi
// 00693ee4  5e                   pop esi
// 00693ee5  59                   pop ecx
// 00693ee6  c20c00               ret 0xc
// standard library vector<pod12> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
