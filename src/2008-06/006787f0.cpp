// from server: 100% by auto
// roc 2008-06 006787f0  unit: Ogre::RbxSceneManagerFactory  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006787f0
//
// 006787f0  56                   push esi
// 006787f1  8bf1                 mov esi, ecx
// 006787f3  8b06                 mov eax, dword ptr [esi]
// 006787f5  57                   push edi
// 006787f6  8b3d90288000         mov edi, dword ptr [0x802890]
// 006787fc  85c0                 test eax, eax
// 006787fe  7508                 jne 0x678808
// 00678800  ffd7                 call edi
// 00678802  8b06                 mov eax, dword ptr [esi]
// 00678804  85c0                 test eax, eax
// 00678806  7404                 je 0x67880c
// 00678808  8b00                 mov eax, dword ptr [eax]
// 0067880a  eb02                 jmp 0x67880e
// 0067880c  33c0                 xor eax, eax
// 0067880e  8b4e04               mov ecx, dword ptr [esi + 4]
// 00678811  3b4818               cmp ecx, dword ptr [eax + 0x18]
// 00678814  7502                 jne 0x678818
// 00678816  ffd7                 call edi
// 00678818  8b4604               mov eax, dword ptr [esi + 4]
// 0067881b  5f                   pop edi
// 0067881c  83c00c               add eax, 0xc
// 0067881f  5e                   pop esi
// 00678820  c3                   ret 
// standard library map_int<ptr> (function ??Dconst_iterator@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@QBEABU?$pair@$$CBHPAUT@@@2@XZ)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
