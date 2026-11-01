// from server: 100% by auto
// roc 2009-12 00719f80  unit: RBX::VPhysicsService::?$EventDesc  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00719f80
//
// 00719f80  56                   push esi
// 00719f81  8bf1                 mov esi, ecx
// 00719f83  833e00               cmp dword ptr [esi], 0
// 00719f86  57                   push edi
// 00719f87  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 00719f8d  7502                 jne 0x719f91
// 00719f8f  ffd7                 call edi
// 00719f91  8b4604               mov eax, dword ptr [esi + 4]
// 00719f94  80781100             cmp byte ptr [eax + 0x11], 0
// 00719f98  7405                 je 0x719f9f
// 00719f9a  ffd7                 call edi
// 00719f9c  5f                   pop edi
// 00719f9d  5e                   pop esi
// 00719f9e  c3                   ret 
// 00719f9f  8b4808               mov ecx, dword ptr [eax + 8]
// 00719fa2  80791100             cmp byte ptr [ecx + 0x11], 0
// 00719fa6  7518                 jne 0x719fc0
// 00719fa8  8b01                 mov eax, dword ptr [ecx]
// 00719faa  80781100             cmp byte ptr [eax + 0x11], 0
// 00719fae  750a                 jne 0x719fba
// 00719fb0  8bc8                 mov ecx, eax
// 00719fb2  8b01                 mov eax, dword ptr [ecx]
// 00719fb4  80781100             cmp byte ptr [eax + 0x11], 0
// 00719fb8  74f6                 je 0x719fb0
// 00719fba  5f                   pop edi
// 00719fbb  894e04               mov dword ptr [esi + 4], ecx
// 00719fbe  5e                   pop esi
// 00719fbf  c3                   ret 
// 00719fc0  8b4004               mov eax, dword ptr [eax + 4]
// 00719fc3  80781100             cmp byte ptr [eax + 0x11], 0
// 00719fc7  751d                 jne 0x719fe6
// 00719fc9  8da42400000000       lea esp, [esp]
// 00719fd0  8b4e04               mov ecx, dword ptr [esi + 4]
// 00719fd3  3b4808               cmp ecx, dword ptr [eax + 8]
// 00719fd6  750e                 jne 0x719fe6
// 00719fd8  894604               mov dword ptr [esi + 4], eax
// 00719fdb  8bd0                 mov edx, eax
// 00719fdd  8b4204               mov eax, dword ptr [edx + 4]
// 00719fe0  80781100             cmp byte ptr [eax + 0x11], 0
// 00719fe4  74ea                 je 0x719fd0
// 00719fe6  5f                   pop edi
// 00719fe7  894604               mov dword ptr [esi + 4], eax
// 00719fea  5e                   pop esi
// 00719feb  c3                   ret 
// standard library set<ptr> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
