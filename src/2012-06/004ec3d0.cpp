// from server: 100% by auto
// roc 2012-06 004ec3d0  unit: Ogre::RbxEntity  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004ec3d0
//
// 004ec3d0  8b442404             mov eax, dword ptr [esp + 4]
// 004ec3d4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004ec3d8  3bc1                 cmp eax, ecx
// 004ec3da  740f                 je 0x4ec3eb
// 004ec3dc  56                   push esi
// 004ec3dd  8b742410             mov esi, dword ptr [esp + 0x10]
// 004ec3e1  8a16                 mov dl, byte ptr [esi]
// 004ec3e3  8810                 mov byte ptr [eax], dl
// 004ec3e5  40                   inc eax
// 004ec3e6  3bc1                 cmp eax, ecx
// 004ec3e8  75f7                 jne 0x4ec3e1
// 004ec3ea  5e                   pop esi
// 004ec3eb  c3                   ret 
// standard library vector<char> (function ??$_Fill@PADD@std@@YAXPAD0ABD@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
