// from server: 100% by auto
// roc 2009-06 0048f650  unit: Ogre::RbxTextureCompositorSceneManager  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048f650
//
// 0048f650  83ec08               sub esp, 8
// 0048f653  53                   push ebx
// 0048f654  55                   push ebp
// 0048f655  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 0048f65b  56                   push esi
// 0048f65c  8bf1                 mov esi, ecx
// 0048f65e  8b4618               mov eax, dword ptr [esi + 0x18]
// 0048f661  8b18                 mov ebx, dword ptr [eax]
// 0048f663  8b06                 mov eax, dword ptr [esi]
// 0048f665  57                   push edi
// 0048f666  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0048f66a  85ff                 test edi, edi
// 0048f66c  7404                 je 0x48f672
// 0048f66e  3bf8                 cmp edi, eax
// 0048f670  7406                 je 0x48f678
// 0048f672  ffd5                 call ebp
// 0048f674  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0048f678  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0048f67c  7562                 jne 0x48f6e0
// 0048f67e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0048f682  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 0048f685  8b06                 mov eax, dword ptr [esi]
// 0048f687  85c9                 test ecx, ecx
// 0048f689  7404                 je 0x48f68f
// 0048f68b  3bc8                 cmp ecx, eax
// 0048f68d  7406                 je 0x48f695
// 0048f68f  ffd5                 call ebp
// 0048f691  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0048f695  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 0048f699  7545                 jne 0x48f6e0
// 0048f69b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0048f69e  8b5104               mov edx, dword ptr [ecx + 4]
// 0048f6a1  52                   push edx
// 0048f6a2  8bce                 mov ecx, esi
// 0048f6a4  e837f5ffff           call 0x48ebe0
// 0048f6a9  8b4618               mov eax, dword ptr [esi + 0x18]
// 0048f6ac  894004               mov dword ptr [eax + 4], eax
// 0048f6af  8b4618               mov eax, dword ptr [esi + 0x18]
// 0048f6b2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0048f6b9  8900                 mov dword ptr [eax], eax
// 0048f6bb  8b4618               mov eax, dword ptr [esi + 0x18]
// 0048f6be  894008               mov dword ptr [eax + 8], eax
// 0048f6c1  8b4618               mov eax, dword ptr [esi + 0x18]
// 0048f6c4  8b16                 mov edx, dword ptr [esi]
// 0048f6c6  8b08                 mov ecx, dword ptr [eax]
// 0048f6c8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0048f6cc  5f                   pop edi
// 0048f6cd  5e                   pop esi
// 0048f6ce  5d                   pop ebp
// 0048f6cf  894804               mov dword ptr [eax + 4], ecx
// 0048f6d2  8910                 mov dword ptr [eax], edx
// 0048f6d4  5b                   pop ebx
// 0048f6d5  83c408               add esp, 8
// 0048f6d8  c21400               ret 0x14
// 0048f6db  eb03                 jmp 0x48f6e0
// 0048f6dd  8d4900               lea ecx, [ecx]
// 0048f6e0  85ff                 test edi, edi
// 0048f6e2  7406                 je 0x48f6ea
// 0048f6e4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 0048f6e8  7406                 je 0x48f6f0
// 0048f6ea  ffd5                 call ebp
// 0048f6ec  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0048f6f0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0048f6f4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 0048f6f8  741d                 je 0x48f717
// 0048f6fa  8d4c2420             lea ecx, [esp + 0x20]
// 0048f6fe  e89dc0ffff           call 0x48b7a0
// 0048f703  53                   push ebx
// 0048f704  57                   push edi
// 0048f705  8d442418             lea eax, [esp + 0x18]
// 0048f709  50                   push eax
// 0048f70a  8bce                 mov ecx, esi
// 0048f70c  e84ff1ffff           call 0x48e860
// 0048f711  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0048f715  ebc9                 jmp 0x48f6e0
// 0048f717  8b36                 mov esi, dword ptr [esi]
// 0048f719  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0048f71d  5f                   pop edi
// 0048f71e  8930                 mov dword ptr [eax], esi
// 0048f720  5e                   pop esi
// 0048f721  5d                   pop ebp
// 0048f722  895804               mov dword ptr [eax + 4], ebx
// 0048f725  5b                   pop ebx
// 0048f726  83c408               add esp, 8
// 0048f729  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
