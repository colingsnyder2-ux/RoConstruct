// from server: 100% by auto
// roc 2009-06 0051c650  unit: RBX::VRenderSurfaceTypes::?$Table  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0051c650
//
// 0051c650  83ec08               sub esp, 8
// 0051c653  53                   push ebx
// 0051c654  55                   push ebp
// 0051c655  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 0051c65b  56                   push esi
// 0051c65c  8bf1                 mov esi, ecx
// 0051c65e  8b4618               mov eax, dword ptr [esi + 0x18]
// 0051c661  8b18                 mov ebx, dword ptr [eax]
// 0051c663  8b06                 mov eax, dword ptr [esi]
// 0051c665  57                   push edi
// 0051c666  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0051c66a  85ff                 test edi, edi
// 0051c66c  7404                 je 0x51c672
// 0051c66e  3bf8                 cmp edi, eax
// 0051c670  7406                 je 0x51c678
// 0051c672  ffd5                 call ebp
// 0051c674  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0051c678  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0051c67c  7562                 jne 0x51c6e0
// 0051c67e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0051c682  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 0051c685  8b06                 mov eax, dword ptr [esi]
// 0051c687  85c9                 test ecx, ecx
// 0051c689  7404                 je 0x51c68f
// 0051c68b  3bc8                 cmp ecx, eax
// 0051c68d  7406                 je 0x51c695
// 0051c68f  ffd5                 call ebp
// 0051c691  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0051c695  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 0051c699  7545                 jne 0x51c6e0
// 0051c69b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0051c69e  8b5104               mov edx, dword ptr [ecx + 4]
// 0051c6a1  52                   push edx
// 0051c6a2  8bce                 mov ecx, esi
// 0051c6a4  e8b7e4ffff           call 0x51ab60
// 0051c6a9  8b4618               mov eax, dword ptr [esi + 0x18]
// 0051c6ac  894004               mov dword ptr [eax + 4], eax
// 0051c6af  8b4618               mov eax, dword ptr [esi + 0x18]
// 0051c6b2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0051c6b9  8900                 mov dword ptr [eax], eax
// 0051c6bb  8b4618               mov eax, dword ptr [esi + 0x18]
// 0051c6be  894008               mov dword ptr [eax + 8], eax
// 0051c6c1  8b4618               mov eax, dword ptr [esi + 0x18]
// 0051c6c4  8b16                 mov edx, dword ptr [esi]
// 0051c6c6  8b08                 mov ecx, dword ptr [eax]
// 0051c6c8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0051c6cc  5f                   pop edi
// 0051c6cd  5e                   pop esi
// 0051c6ce  5d                   pop ebp
// 0051c6cf  894804               mov dword ptr [eax + 4], ecx
// 0051c6d2  8910                 mov dword ptr [eax], edx
// 0051c6d4  5b                   pop ebx
// 0051c6d5  83c408               add esp, 8
// 0051c6d8  c21400               ret 0x14
// 0051c6db  eb03                 jmp 0x51c6e0
// 0051c6dd  8d4900               lea ecx, [ecx]
// 0051c6e0  85ff                 test edi, edi
// 0051c6e2  7406                 je 0x51c6ea
// 0051c6e4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 0051c6e8  7406                 je 0x51c6f0
// 0051c6ea  ffd5                 call ebp
// 0051c6ec  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0051c6f0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0051c6f4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 0051c6f8  741d                 je 0x51c717
// 0051c6fa  8d4c2420             lea ecx, [esp + 0x20]
// 0051c6fe  e86db1ffff           call 0x517870
// 0051c703  53                   push ebx
// 0051c704  57                   push edi
// 0051c705  8d442418             lea eax, [esp + 0x18]
// 0051c709  50                   push eax
// 0051c70a  8bce                 mov ecx, esi
// 0051c70c  e82fe1ffff           call 0x51a840
// 0051c711  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0051c715  ebc9                 jmp 0x51c6e0
// 0051c717  8b36                 mov esi, dword ptr [esi]
// 0051c719  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0051c71d  5f                   pop edi
// 0051c71e  8930                 mov dword ptr [eax], esi
// 0051c720  5e                   pop esi
// 0051c721  5d                   pop ebp
// 0051c722  895804               mov dword ptr [eax + 4], ebx
// 0051c725  5b                   pop ebx
// 0051c726  83c408               add esp, 8
// 0051c729  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
