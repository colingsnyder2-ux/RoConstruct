// from server: 100% by auto
// roc 2009-12 004bddc0  unit: Ogre::RbxSpatialHashedSceneNode::?1??_findVisibleObjects::NodeVisiter  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004bddc0
//
// 004bddc0  53                   push ebx
// 004bddc1  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 004bddc7  56                   push esi
// 004bddc8  8b31                 mov esi, dword ptr [ecx]
// 004bddca  57                   push edi
// 004bddcb  8b7904               mov edi, dword ptr [ecx + 4]
// 004bddce  85f6                 test esi, esi
// 004bddd0  7518                 jne 0x4bddea
// 004bddd2  ffd3                 call ebx
// 004bddd4  33c0                 xor eax, eax
// 004bddd6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004bddda  8d3ccf               lea edi, [edi + ecx*8]
// 004bdddd  3b7810               cmp edi, dword ptr [eax + 0x10]
// 004bdde0  7713                 ja 0x4bddf5
// 004bdde2  85f6                 test esi, esi
// 004bdde4  7408                 je 0x4bddee
// 004bdde6  8b06                 mov eax, dword ptr [esi]
// 004bdde8  eb06                 jmp 0x4bddf0
// 004bddea  8b06                 mov eax, dword ptr [esi]
// 004bddec  ebe8                 jmp 0x4bddd6
// 004bddee  33c0                 xor eax, eax
// 004bddf0  3b780c               cmp edi, dword ptr [eax + 0xc]
// 004bddf3  7302                 jae 0x4bddf7
// 004bddf5  ffd3                 call ebx
// 004bddf7  8b442410             mov eax, dword ptr [esp + 0x10]
// 004bddfb  897804               mov dword ptr [eax + 4], edi
// 004bddfe  5f                   pop edi
// 004bddff  8930                 mov dword ptr [eax], esi
// 004bde01  5e                   pop esi
// 004bde02  5b                   pop ebx
// 004bde03  c20800               ret 8
// standard library vector<double> (function ??H?$_Vector_const_iterator@NV?$allocator@N@std@@@std@@QBE?AV01@H@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
