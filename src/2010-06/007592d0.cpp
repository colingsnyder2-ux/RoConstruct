// from server: 100% by auto
// roc 2010-06 007592d0  unit: RBX::PyramidPoly  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007592d0
//
// 007592d0  83ec08               sub esp, 8
// 007592d3  53                   push ebx
// 007592d4  55                   push ebp
// 007592d5  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 007592db  56                   push esi
// 007592dc  8bf1                 mov esi, ecx
// 007592de  8b4618               mov eax, dword ptr [esi + 0x18]
// 007592e1  8b18                 mov ebx, dword ptr [eax]
// 007592e3  8b06                 mov eax, dword ptr [esi]
// 007592e5  57                   push edi
// 007592e6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007592ea  85ff                 test edi, edi
// 007592ec  7404                 je 0x7592f2
// 007592ee  3bf8                 cmp edi, eax
// 007592f0  7406                 je 0x7592f8
// 007592f2  ffd5                 call ebp
// 007592f4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007592f8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 007592fc  7562                 jne 0x759360
// 007592fe  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00759302  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00759305  8b06                 mov eax, dword ptr [esi]
// 00759307  85c9                 test ecx, ecx
// 00759309  7404                 je 0x75930f
// 0075930b  3bc8                 cmp ecx, eax
// 0075930d  7406                 je 0x759315
// 0075930f  ffd5                 call ebp
// 00759311  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00759315  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00759319  7545                 jne 0x759360
// 0075931b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0075931e  8b5104               mov edx, dword ptr [ecx + 4]
// 00759321  52                   push edx
// 00759322  8bce                 mov ecx, esi
// 00759324  e897fcffff           call 0x758fc0
// 00759329  8b4618               mov eax, dword ptr [esi + 0x18]
// 0075932c  894004               mov dword ptr [eax + 4], eax
// 0075932f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00759332  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00759339  8900                 mov dword ptr [eax], eax
// 0075933b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0075933e  894008               mov dword ptr [eax + 8], eax
// 00759341  8b4618               mov eax, dword ptr [esi + 0x18]
// 00759344  8b16                 mov edx, dword ptr [esi]
// 00759346  8b08                 mov ecx, dword ptr [eax]
// 00759348  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0075934c  5f                   pop edi
// 0075934d  5e                   pop esi
// 0075934e  5d                   pop ebp
// 0075934f  894804               mov dword ptr [eax + 4], ecx
// 00759352  8910                 mov dword ptr [eax], edx
// 00759354  5b                   pop ebx
// 00759355  83c408               add esp, 8
// 00759358  c21400               ret 0x14
// 0075935b  eb03                 jmp 0x759360
// 0075935d  8d4900               lea ecx, [ecx]
// 00759360  85ff                 test edi, edi
// 00759362  7406                 je 0x75936a
// 00759364  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00759368  7406                 je 0x759370
// 0075936a  ffd5                 call ebp
// 0075936c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00759370  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00759374  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00759378  741d                 je 0x759397
// 0075937a  8d4c2420             lea ecx, [esp + 0x20]
// 0075937e  e88dfbffff           call 0x758f10
// 00759383  53                   push ebx
// 00759384  57                   push edi
// 00759385  8d442418             lea eax, [esp + 0x18]
// 00759389  50                   push eax
// 0075938a  8bce                 mov ecx, esi
// 0075938c  e86ffcffff           call 0x759000
// 00759391  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00759395  ebc9                 jmp 0x759360
// 00759397  8b36                 mov esi, dword ptr [esi]
// 00759399  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0075939d  5f                   pop edi
// 0075939e  8930                 mov dword ptr [eax], esi
// 007593a0  5e                   pop esi
// 007593a1  5d                   pop ebp
// 007593a2  895804               mov dword ptr [eax + 4], ebx
// 007593a5  5b                   pop ebx
// 007593a6  83c408               add esp, 8
// 007593a9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
