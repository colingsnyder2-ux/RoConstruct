// from server: 100% by auto
// roc 2009-06 00476410  unit: Ogre::RbxMeshLoader  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00476410
//
// 00476410  56                   push esi
// 00476411  8bf1                 mov esi, ecx
// 00476413  8b06                 mov eax, dword ptr [esi]
// 00476415  57                   push edi
// 00476416  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 0047641c  85c0                 test eax, eax
// 0047641e  7508                 jne 0x476428
// 00476420  ffd7                 call edi
// 00476422  8b06                 mov eax, dword ptr [esi]
// 00476424  85c0                 test eax, eax
// 00476426  7404                 je 0x47642c
// 00476428  8b00                 mov eax, dword ptr [eax]
// 0047642a  eb02                 jmp 0x47642e
// 0047642c  33c0                 xor eax, eax
// 0047642e  8b4e04               mov ecx, dword ptr [esi + 4]
// 00476431  3b4818               cmp ecx, dword ptr [eax + 0x18]
// 00476434  7502                 jne 0x476438
// 00476436  ffd7                 call edi
// 00476438  8b4604               mov eax, dword ptr [esi + 4]
// 0047643b  5f                   pop edi
// 0047643c  83c00c               add eax, 0xc
// 0047643f  5e                   pop esi
// 00476440  c3                   ret 
// standard library map_int<ptr> (function ??Dconst_iterator@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@QBEABU?$pair@$$CBHPAUT@@@2@XZ)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
