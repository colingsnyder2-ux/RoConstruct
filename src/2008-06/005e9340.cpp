// from server: 100% by auto
// roc 2008-06 005e9340  unit: RBX::PhysicsService  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e9340
//
// 005e9340  56                   push esi
// 005e9341  8bf1                 mov esi, ecx
// 005e9343  833e00               cmp dword ptr [esi], 0
// 005e9346  57                   push edi
// 005e9347  8b3d90288000         mov edi, dword ptr [0x802890]
// 005e934d  7502                 jne 0x5e9351
// 005e934f  ffd7                 call edi
// 005e9351  8b4604               mov eax, dword ptr [esi + 4]
// 005e9354  80781100             cmp byte ptr [eax + 0x11], 0
// 005e9358  7405                 je 0x5e935f
// 005e935a  ffd7                 call edi
// 005e935c  5f                   pop edi
// 005e935d  5e                   pop esi
// 005e935e  c3                   ret 
// 005e935f  8b4808               mov ecx, dword ptr [eax + 8]
// 005e9362  80791100             cmp byte ptr [ecx + 0x11], 0
// 005e9366  7518                 jne 0x5e9380
// 005e9368  8b01                 mov eax, dword ptr [ecx]
// 005e936a  80781100             cmp byte ptr [eax + 0x11], 0
// 005e936e  750a                 jne 0x5e937a
// 005e9370  8bc8                 mov ecx, eax
// 005e9372  8b01                 mov eax, dword ptr [ecx]
// 005e9374  80781100             cmp byte ptr [eax + 0x11], 0
// 005e9378  74f6                 je 0x5e9370
// 005e937a  5f                   pop edi
// 005e937b  894e04               mov dword ptr [esi + 4], ecx
// 005e937e  5e                   pop esi
// 005e937f  c3                   ret 
// 005e9380  8b4004               mov eax, dword ptr [eax + 4]
// 005e9383  80781100             cmp byte ptr [eax + 0x11], 0
// 005e9387  751d                 jne 0x5e93a6
// 005e9389  8da42400000000       lea esp, [esp]
// 005e9390  8b4e04               mov ecx, dword ptr [esi + 4]
// 005e9393  3b4808               cmp ecx, dword ptr [eax + 8]
// 005e9396  750e                 jne 0x5e93a6
// 005e9398  894604               mov dword ptr [esi + 4], eax
// 005e939b  8bd0                 mov edx, eax
// 005e939d  8b4204               mov eax, dword ptr [edx + 4]
// 005e93a0  80781100             cmp byte ptr [eax + 0x11], 0
// 005e93a4  74ea                 je 0x5e9390
// 005e93a6  5f                   pop edi
// 005e93a7  894604               mov dword ptr [esi + 4], eax
// 005e93aa  5e                   pop esi
// 005e93ab  c3                   ret 
// standard library set<ptr> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
