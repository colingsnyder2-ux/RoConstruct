// from server: 100% by auto
// roc 2009-06 00496940  unit: Ogre::TwoDManager  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00496940
//
// 00496940  51                   push ecx
// 00496941  8b542410             mov edx, dword ptr [esp + 0x10]
// 00496945  56                   push esi
// 00496946  8b742410             mov esi, dword ptr [esp + 0x10]
// 0049694a  57                   push edi
// 0049694b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0049694f  c644240800           mov byte ptr [esp + 8], 0
// 00496954  8b442408             mov eax, dword ptr [esp + 8]
// 00496958  50                   push eax
// 00496959  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0049695d  52                   push edx
// 0049695e  83c108               add ecx, 8
// 00496961  51                   push ecx
// 00496962  50                   push eax
// 00496963  56                   push esi
// 00496964  57                   push edi
// 00496965  e876c4feff           call 0x482de0
// 0049696a  83c418               add esp, 0x18
// 0049696d  8d04f7               lea eax, [edi + esi*8]
// 00496970  5f                   pop edi
// 00496971  5e                   pop esi
// 00496972  59                   pop ecx
// 00496973  c20c00               ret 0xc
// standard library vector<pod8> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
