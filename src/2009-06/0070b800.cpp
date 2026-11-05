// from server: 100% by auto
// roc 2009-06 0070b800  unit: RBX::VCEvent::?$sp_counted_impl_p  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0070b800
//
// 0070b800  83ec08               sub esp, 8
// 0070b803  53                   push ebx
// 0070b804  55                   push ebp
// 0070b805  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 0070b80b  56                   push esi
// 0070b80c  8bf1                 mov esi, ecx
// 0070b80e  8b4618               mov eax, dword ptr [esi + 0x18]
// 0070b811  8b18                 mov ebx, dword ptr [eax]
// 0070b813  8b06                 mov eax, dword ptr [esi]
// 0070b815  57                   push edi
// 0070b816  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0070b81a  85ff                 test edi, edi
// 0070b81c  7404                 je 0x70b822
// 0070b81e  3bf8                 cmp edi, eax
// 0070b820  7406                 je 0x70b828
// 0070b822  ffd5                 call ebp
// 0070b824  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0070b828  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0070b82c  7562                 jne 0x70b890
// 0070b82e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0070b832  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 0070b835  8b06                 mov eax, dword ptr [esi]
// 0070b837  85c9                 test ecx, ecx
// 0070b839  7404                 je 0x70b83f
// 0070b83b  3bc8                 cmp ecx, eax
// 0070b83d  7406                 je 0x70b845
// 0070b83f  ffd5                 call ebp
// 0070b841  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0070b845  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 0070b849  7545                 jne 0x70b890
// 0070b84b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0070b84e  8b5104               mov edx, dword ptr [ecx + 4]
// 0070b851  52                   push edx
// 0070b852  8bce                 mov ecx, esi
// 0070b854  e807fcffff           call 0x70b460
// 0070b859  8b4618               mov eax, dword ptr [esi + 0x18]
// 0070b85c  894004               mov dword ptr [eax + 4], eax
// 0070b85f  8b4618               mov eax, dword ptr [esi + 0x18]
// 0070b862  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0070b869  8900                 mov dword ptr [eax], eax
// 0070b86b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0070b86e  894008               mov dword ptr [eax + 8], eax
// 0070b871  8b4618               mov eax, dword ptr [esi + 0x18]
// 0070b874  8b16                 mov edx, dword ptr [esi]
// 0070b876  8b08                 mov ecx, dword ptr [eax]
// 0070b878  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0070b87c  5f                   pop edi
// 0070b87d  5e                   pop esi
// 0070b87e  5d                   pop ebp
// 0070b87f  894804               mov dword ptr [eax + 4], ecx
// 0070b882  8910                 mov dword ptr [eax], edx
// 0070b884  5b                   pop ebx
// 0070b885  83c408               add esp, 8
// 0070b888  c21400               ret 0x14
// 0070b88b  eb03                 jmp 0x70b890
// 0070b88d  8d4900               lea ecx, [ecx]
// 0070b890  85ff                 test edi, edi
// 0070b892  7406                 je 0x70b89a
// 0070b894  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 0070b898  7406                 je 0x70b8a0
// 0070b89a  ffd5                 call ebp
// 0070b89c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0070b8a0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0070b8a4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 0070b8a8  741d                 je 0x70b8c7
// 0070b8aa  8d4c2420             lea ecx, [esp + 0x20]
// 0070b8ae  e8bdd8edff           call 0x5e9170
// 0070b8b3  53                   push ebx
// 0070b8b4  57                   push edi
// 0070b8b5  8d442418             lea eax, [esp + 0x18]
// 0070b8b9  50                   push eax
// 0070b8ba  8bce                 mov ecx, esi
// 0070b8bc  e89ff8ffff           call 0x70b160
// 0070b8c1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0070b8c5  ebc9                 jmp 0x70b890
// 0070b8c7  8b36                 mov esi, dword ptr [esi]
// 0070b8c9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0070b8cd  5f                   pop edi
// 0070b8ce  8930                 mov dword ptr [eax], esi
// 0070b8d0  5e                   pop esi
// 0070b8d1  5d                   pop ebp
// 0070b8d2  895804               mov dword ptr [eax + 4], ebx
// 0070b8d5  5b                   pop ebx
// 0070b8d6  83c408               add esp, 8
// 0070b8d9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
