// from server: 100% by auto
// roc 2010-06 008d9bc0  unit: Ogre::RbxTextureCompositorSceneManager  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d9bc0
//
// 008d9bc0  83ec08               sub esp, 8
// 008d9bc3  53                   push ebx
// 008d9bc4  55                   push ebp
// 008d9bc5  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 008d9bcb  56                   push esi
// 008d9bcc  8bf1                 mov esi, ecx
// 008d9bce  8b4618               mov eax, dword ptr [esi + 0x18]
// 008d9bd1  8b18                 mov ebx, dword ptr [eax]
// 008d9bd3  8b06                 mov eax, dword ptr [esi]
// 008d9bd5  57                   push edi
// 008d9bd6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 008d9bda  85ff                 test edi, edi
// 008d9bdc  7404                 je 0x8d9be2
// 008d9bde  3bf8                 cmp edi, eax
// 008d9be0  7406                 je 0x8d9be8
// 008d9be2  ffd5                 call ebp
// 008d9be4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 008d9be8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 008d9bec  7562                 jne 0x8d9c50
// 008d9bee  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 008d9bf2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 008d9bf5  8b06                 mov eax, dword ptr [esi]
// 008d9bf7  85c9                 test ecx, ecx
// 008d9bf9  7404                 je 0x8d9bff
// 008d9bfb  3bc8                 cmp ecx, eax
// 008d9bfd  7406                 je 0x8d9c05
// 008d9bff  ffd5                 call ebp
// 008d9c01  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 008d9c05  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 008d9c09  7545                 jne 0x8d9c50
// 008d9c0b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 008d9c0e  8b5104               mov edx, dword ptr [ecx + 4]
// 008d9c11  52                   push edx
// 008d9c12  8bce                 mov ecx, esi
// 008d9c14  e8c7f3ffff           call 0x8d8fe0
// 008d9c19  8b4618               mov eax, dword ptr [esi + 0x18]
// 008d9c1c  894004               mov dword ptr [eax + 4], eax
// 008d9c1f  8b4618               mov eax, dword ptr [esi + 0x18]
// 008d9c22  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 008d9c29  8900                 mov dword ptr [eax], eax
// 008d9c2b  8b4618               mov eax, dword ptr [esi + 0x18]
// 008d9c2e  894008               mov dword ptr [eax + 8], eax
// 008d9c31  8b4618               mov eax, dword ptr [esi + 0x18]
// 008d9c34  8b16                 mov edx, dword ptr [esi]
// 008d9c36  8b08                 mov ecx, dword ptr [eax]
// 008d9c38  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008d9c3c  5f                   pop edi
// 008d9c3d  5e                   pop esi
// 008d9c3e  5d                   pop ebp
// 008d9c3f  894804               mov dword ptr [eax + 4], ecx
// 008d9c42  8910                 mov dword ptr [eax], edx
// 008d9c44  5b                   pop ebx
// 008d9c45  83c408               add esp, 8
// 008d9c48  c21400               ret 0x14
// 008d9c4b  eb03                 jmp 0x8d9c50
// 008d9c4d  8d4900               lea ecx, [ecx]
// 008d9c50  85ff                 test edi, edi
// 008d9c52  7406                 je 0x8d9c5a
// 008d9c54  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 008d9c58  7406                 je 0x8d9c60
// 008d9c5a  ffd5                 call ebp
// 008d9c5c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 008d9c60  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 008d9c64  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 008d9c68  741d                 je 0x8d9c87
// 008d9c6a  8d4c2420             lea ecx, [esp + 0x20]
// 008d9c6e  e82d0fdaff           call 0x67aba0
// 008d9c73  53                   push ebx
// 008d9c74  57                   push edi
// 008d9c75  8d442418             lea eax, [esp + 0x18]
// 008d9c79  50                   push eax
// 008d9c7a  8bce                 mov ecx, esi
// 008d9c7c  e85ff0ffff           call 0x8d8ce0
// 008d9c81  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 008d9c85  ebc9                 jmp 0x8d9c50
// 008d9c87  8b36                 mov esi, dword ptr [esi]
// 008d9c89  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008d9c8d  5f                   pop edi
// 008d9c8e  8930                 mov dword ptr [eax], esi
// 008d9c90  5e                   pop esi
// 008d9c91  5d                   pop ebp
// 008d9c92  895804               mov dword ptr [eax + 4], ebx
// 008d9c95  5b                   pop ebx
// 008d9c96  83c408               add esp, 8
// 008d9c99  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
