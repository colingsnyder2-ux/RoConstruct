// from server: 100% by auto
// roc 2009-12 00490a90  unit: Ogre::RbxEntity  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00490a90
//
// 00490a90  8b442404             mov eax, dword ptr [esp + 4]
// 00490a94  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00490a98  3bc1                 cmp eax, ecx
// 00490a9a  740f                 je 0x490aab
// 00490a9c  56                   push esi
// 00490a9d  8b742410             mov esi, dword ptr [esp + 0x10]
// 00490aa1  8a16                 mov dl, byte ptr [esi]
// 00490aa3  8810                 mov byte ptr [eax], dl
// 00490aa5  40                   inc eax
// 00490aa6  3bc1                 cmp eax, ecx
// 00490aa8  75f7                 jne 0x490aa1
// 00490aaa  5e                   pop esi
// 00490aab  c3                   ret 
// standard library vector<char> (function ??$_Fill@PADD@std@@YAXPAD0ABD@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
