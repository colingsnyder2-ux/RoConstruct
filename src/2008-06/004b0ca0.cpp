// from server: 100% by auto
// roc 2008-06 004b0ca0  unit: RBX::Network::Replicator::NewInstanceItem  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004b0ca0
//
// 004b0ca0  83ec08               sub esp, 8
// 004b0ca3  53                   push ebx
// 004b0ca4  55                   push ebp
// 004b0ca5  8b2d90288000         mov ebp, dword ptr [0x802890]
// 004b0cab  56                   push esi
// 004b0cac  8bf1                 mov esi, ecx
// 004b0cae  8b4618               mov eax, dword ptr [esi + 0x18]
// 004b0cb1  8b18                 mov ebx, dword ptr [eax]
// 004b0cb3  8b06                 mov eax, dword ptr [esi]
// 004b0cb5  57                   push edi
// 004b0cb6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004b0cba  85ff                 test edi, edi
// 004b0cbc  7404                 je 0x4b0cc2
// 004b0cbe  3bf8                 cmp edi, eax
// 004b0cc0  7406                 je 0x4b0cc8
// 004b0cc2  ffd5                 call ebp
// 004b0cc4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004b0cc8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 004b0ccc  7562                 jne 0x4b0d30
// 004b0cce  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004b0cd2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 004b0cd5  8b06                 mov eax, dword ptr [esi]
// 004b0cd7  85c9                 test ecx, ecx
// 004b0cd9  7404                 je 0x4b0cdf
// 004b0cdb  3bc8                 cmp ecx, eax
// 004b0cdd  7406                 je 0x4b0ce5
// 004b0cdf  ffd5                 call ebp
// 004b0ce1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004b0ce5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 004b0ce9  7545                 jne 0x4b0d30
// 004b0ceb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004b0cee  8b5104               mov edx, dword ptr [ecx + 4]
// 004b0cf1  52                   push edx
// 004b0cf2  8bce                 mov ecx, esi
// 004b0cf4  e8c7e3ffff           call 0x4af0c0
// 004b0cf9  8b4618               mov eax, dword ptr [esi + 0x18]
// 004b0cfc  894004               mov dword ptr [eax + 4], eax
// 004b0cff  8b4618               mov eax, dword ptr [esi + 0x18]
// 004b0d02  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004b0d09  8900                 mov dword ptr [eax], eax
// 004b0d0b  8b4618               mov eax, dword ptr [esi + 0x18]
// 004b0d0e  894008               mov dword ptr [eax + 8], eax
// 004b0d11  8b4618               mov eax, dword ptr [esi + 0x18]
// 004b0d14  8b16                 mov edx, dword ptr [esi]
// 004b0d16  8b08                 mov ecx, dword ptr [eax]
// 004b0d18  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004b0d1c  5f                   pop edi
// 004b0d1d  5e                   pop esi
// 004b0d1e  5d                   pop ebp
// 004b0d1f  894804               mov dword ptr [eax + 4], ecx
// 004b0d22  8910                 mov dword ptr [eax], edx
// 004b0d24  5b                   pop ebx
// 004b0d25  83c408               add esp, 8
// 004b0d28  c21400               ret 0x14
// 004b0d2b  eb03                 jmp 0x4b0d30
// 004b0d2d  8d4900               lea ecx, [ecx]
// 004b0d30  85ff                 test edi, edi
// 004b0d32  7406                 je 0x4b0d3a
// 004b0d34  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004b0d38  7406                 je 0x4b0d40
// 004b0d3a  ffd5                 call ebp
// 004b0d3c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004b0d40  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004b0d44  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004b0d48  741d                 je 0x4b0d67
// 004b0d4a  8d4c2420             lea ecx, [esp + 0x20]
// 004b0d4e  e8cdbc0a00           call 0x55ca20
// 004b0d53  53                   push ebx
// 004b0d54  57                   push edi
// 004b0d55  8d442418             lea eax, [esp + 0x18]
// 004b0d59  50                   push eax
// 004b0d5a  8bce                 mov ecx, esi
// 004b0d5c  e89fdfffff           call 0x4aed00
// 004b0d61  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004b0d65  ebc9                 jmp 0x4b0d30
// 004b0d67  8b36                 mov esi, dword ptr [esi]
// 004b0d69  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004b0d6d  5f                   pop edi
// 004b0d6e  8930                 mov dword ptr [eax], esi
// 004b0d70  5e                   pop esi
// 004b0d71  5d                   pop ebp
// 004b0d72  895804               mov dword ptr [eax + 4], ebx
// 004b0d75  5b                   pop ebx
// 004b0d76  83c408               add esp, 8
// 004b0d79  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
