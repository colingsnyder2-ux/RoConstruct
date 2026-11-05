// from server: 100% by auto
// roc 2008-06 0068d510  unit: Ogre::VShadowCameraSetup::?$SharedPtr  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068d510
//
// 0068d510  8b442404             mov eax, dword ptr [esp + 4]
// 0068d514  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0068d518  3bc1                 cmp eax, ecx
// 0068d51a  741b                 je 0x68d537
// 0068d51c  56                   push esi
// 0068d51d  8d4900               lea ecx, [ecx]
// 0068d520  83e904               sub ecx, 4
// 0068d523  3bc1                 cmp eax, ecx
// 0068d525  740f                 je 0x68d536
// 0068d527  8b10                 mov edx, dword ptr [eax]
// 0068d529  8b31                 mov esi, dword ptr [ecx]
// 0068d52b  8930                 mov dword ptr [eax], esi
// 0068d52d  83c004               add eax, 4
// 0068d530  8911                 mov dword ptr [ecx], edx
// 0068d532  3bc1                 cmp eax, ecx
// 0068d534  75ea                 jne 0x68d520
// 0068d536  5e                   pop esi
// 0068d537  c20800               ret 8
// standard library vector<ptr> (function ?_Reverse@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXPAPAUT@@0@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
