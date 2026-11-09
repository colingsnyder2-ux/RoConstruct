// from server: 100% by auto
// roc 2010-06 005eb240  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005eb240
//
// 005eb240  83ec08               sub esp, 8
// 005eb243  53                   push ebx
// 005eb244  55                   push ebp
// 005eb245  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 005eb24b  56                   push esi
// 005eb24c  8bf1                 mov esi, ecx
// 005eb24e  8b4618               mov eax, dword ptr [esi + 0x18]
// 005eb251  8b18                 mov ebx, dword ptr [eax]
// 005eb253  8b06                 mov eax, dword ptr [esi]
// 005eb255  57                   push edi
// 005eb256  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005eb25a  85ff                 test edi, edi
// 005eb25c  7404                 je 0x5eb262
// 005eb25e  3bf8                 cmp edi, eax
// 005eb260  7406                 je 0x5eb268
// 005eb262  ffd5                 call ebp
// 005eb264  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005eb268  395c2424             cmp dword ptr [esp + 0x24], ebx
// 005eb26c  7562                 jne 0x5eb2d0
// 005eb26e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005eb272  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 005eb275  8b06                 mov eax, dword ptr [esi]
// 005eb277  85c9                 test ecx, ecx
// 005eb279  7404                 je 0x5eb27f
// 005eb27b  3bc8                 cmp ecx, eax
// 005eb27d  7406                 je 0x5eb285
// 005eb27f  ffd5                 call ebp
// 005eb281  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005eb285  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 005eb289  7545                 jne 0x5eb2d0
// 005eb28b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005eb28e  8b5104               mov edx, dword ptr [ecx + 4]
// 005eb291  52                   push edx
// 005eb292  8bce                 mov ecx, esi
// 005eb294  e887f1ffff           call 0x5ea420
// 005eb299  8b4618               mov eax, dword ptr [esi + 0x18]
// 005eb29c  894004               mov dword ptr [eax + 4], eax
// 005eb29f  8b4618               mov eax, dword ptr [esi + 0x18]
// 005eb2a2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 005eb2a9  8900                 mov dword ptr [eax], eax
// 005eb2ab  8b4618               mov eax, dword ptr [esi + 0x18]
// 005eb2ae  894008               mov dword ptr [eax + 8], eax
// 005eb2b1  8b4618               mov eax, dword ptr [esi + 0x18]
// 005eb2b4  8b16                 mov edx, dword ptr [esi]
// 005eb2b6  8b08                 mov ecx, dword ptr [eax]
// 005eb2b8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005eb2bc  5f                   pop edi
// 005eb2bd  5e                   pop esi
// 005eb2be  5d                   pop ebp
// 005eb2bf  894804               mov dword ptr [eax + 4], ecx
// 005eb2c2  8910                 mov dword ptr [eax], edx
// 005eb2c4  5b                   pop ebx
// 005eb2c5  83c408               add esp, 8
// 005eb2c8  c21400               ret 0x14
// 005eb2cb  eb03                 jmp 0x5eb2d0
// 005eb2cd  8d4900               lea ecx, [ecx]
// 005eb2d0  85ff                 test edi, edi
// 005eb2d2  7406                 je 0x5eb2da
// 005eb2d4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 005eb2d8  7406                 je 0x5eb2e0
// 005eb2da  ffd5                 call ebp
// 005eb2dc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005eb2e0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 005eb2e4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 005eb2e8  741d                 je 0x5eb307
// 005eb2ea  8d4c2420             lea ecx, [esp + 0x20]
// 005eb2ee  e83db7efff           call 0x4e6a30
// 005eb2f3  53                   push ebx
// 005eb2f4  57                   push edi
// 005eb2f5  8d442418             lea eax, [esp + 0x18]
// 005eb2f9  50                   push eax
// 005eb2fa  8bce                 mov ecx, esi
// 005eb2fc  e85ff2ffff           call 0x5ea560
// 005eb301  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005eb305  ebc9                 jmp 0x5eb2d0
// 005eb307  8b36                 mov esi, dword ptr [esi]
// 005eb309  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005eb30d  5f                   pop edi
// 005eb30e  8930                 mov dword ptr [eax], esi
// 005eb310  5e                   pop esi
// 005eb311  5d                   pop ebp
// 005eb312  895804               mov dword ptr [eax + 4], ebx
// 005eb315  5b                   pop ebx
// 005eb316  83c408               add esp, 8
// 005eb319  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
