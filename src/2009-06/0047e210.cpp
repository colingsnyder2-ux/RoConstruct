// from server: 100% by auto
// roc 2009-06 0047e210  unit: Ogre::RbxPart  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0047e210
//
// 0047e210  51                   push ecx
// 0047e211  8b542410             mov edx, dword ptr [esp + 0x10]
// 0047e215  56                   push esi
// 0047e216  8b742410             mov esi, dword ptr [esp + 0x10]
// 0047e21a  57                   push edi
// 0047e21b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0047e21f  c644240800           mov byte ptr [esp + 8], 0
// 0047e224  8b442408             mov eax, dword ptr [esp + 8]
// 0047e228  50                   push eax
// 0047e229  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0047e22d  52                   push edx
// 0047e22e  83c108               add ecx, 8
// 0047e231  51                   push ecx
// 0047e232  50                   push eax
// 0047e233  56                   push esi
// 0047e234  57                   push edi
// 0047e235  e876feffff           call 0x47e0b0
// 0047e23a  83c418               add esp, 0x18
// 0047e23d  8d04f7               lea eax, [edi + esi*8]
// 0047e240  5f                   pop edi
// 0047e241  5e                   pop esi
// 0047e242  59                   pop ecx
// 0047e243  c20c00               ret 0xc
// standard library vector<pod8> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
