// from server: 100% by auto
// roc 2009-12 00491db0  unit: Ogre::RbxEntity  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00491db0
//
// 00491db0  51                   push ecx
// 00491db1  8b542410             mov edx, dword ptr [esp + 0x10]
// 00491db5  56                   push esi
// 00491db6  8b742410             mov esi, dword ptr [esp + 0x10]
// 00491dba  57                   push edi
// 00491dbb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00491dbf  c644240800           mov byte ptr [esp + 8], 0
// 00491dc4  8b442408             mov eax, dword ptr [esp + 8]
// 00491dc8  50                   push eax
// 00491dc9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00491dcd  52                   push edx
// 00491dce  83c108               add ecx, 8
// 00491dd1  51                   push ecx
// 00491dd2  50                   push eax
// 00491dd3  56                   push esi
// 00491dd4  57                   push edi
// 00491dd5  e8e6f71100           call 0x5b15c0
// 00491dda  8d0c76               lea ecx, [esi + esi*2]
// 00491ddd  83c418               add esp, 0x18
// 00491de0  8d048f               lea eax, [edi + ecx*4]
// 00491de3  5f                   pop edi
// 00491de4  5e                   pop esi
// 00491de5  59                   pop ecx
// 00491de6  c20c00               ret 0xc
// standard library vector<pod12> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
