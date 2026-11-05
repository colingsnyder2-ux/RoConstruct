// from server: 100% by auto
// roc 2009-06 0048aa20  unit: Ogre::FileStreamDataStream  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048aa20
//
// 0048aa20  8b442404             mov eax, dword ptr [esp + 4]
// 0048aa24  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0048aa28  3bc1                 cmp eax, ecx
// 0048aa2a  740f                 je 0x48aa3b
// 0048aa2c  56                   push esi
// 0048aa2d  8b742410             mov esi, dword ptr [esp + 0x10]
// 0048aa31  8a16                 mov dl, byte ptr [esi]
// 0048aa33  8810                 mov byte ptr [eax], dl
// 0048aa35  40                   inc eax
// 0048aa36  3bc1                 cmp eax, ecx
// 0048aa38  75f7                 jne 0x48aa31
// 0048aa3a  5e                   pop esi
// 0048aa3b  c3                   ret 
// standard library vector<char> (function ??$_Fill@PADD@std@@YAXPAD0ABD@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
