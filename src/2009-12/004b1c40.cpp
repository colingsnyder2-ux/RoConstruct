// from server: 100% by auto
// roc 2009-12 004b1c40  unit: Ogre::RbxTextureCompositorSceneManager  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b1c40
//
// 004b1c40  83ec08               sub esp, 8
// 004b1c43  53                   push ebx
// 004b1c44  55                   push ebp
// 004b1c45  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 004b1c4b  56                   push esi
// 004b1c4c  8bf1                 mov esi, ecx
// 004b1c4e  8b4618               mov eax, dword ptr [esi + 0x18]
// 004b1c51  8b18                 mov ebx, dword ptr [eax]
// 004b1c53  8b06                 mov eax, dword ptr [esi]
// 004b1c55  57                   push edi
// 004b1c56  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004b1c5a  85ff                 test edi, edi
// 004b1c5c  7404                 je 0x4b1c62
// 004b1c5e  3bf8                 cmp edi, eax
// 004b1c60  7406                 je 0x4b1c68
// 004b1c62  ffd5                 call ebp
// 004b1c64  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004b1c68  395c2424             cmp dword ptr [esp + 0x24], ebx
// 004b1c6c  7562                 jne 0x4b1cd0
// 004b1c6e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004b1c72  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 004b1c75  8b06                 mov eax, dword ptr [esi]
// 004b1c77  85c9                 test ecx, ecx
// 004b1c79  7404                 je 0x4b1c7f
// 004b1c7b  3bc8                 cmp ecx, eax
// 004b1c7d  7406                 je 0x4b1c85
// 004b1c7f  ffd5                 call ebp
// 004b1c81  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004b1c85  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 004b1c89  7545                 jne 0x4b1cd0
// 004b1c8b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004b1c8e  8b5104               mov edx, dword ptr [ecx + 4]
// 004b1c91  52                   push edx
// 004b1c92  8bce                 mov ecx, esi
// 004b1c94  e8e7f3ffff           call 0x4b1080
// 004b1c99  8b4618               mov eax, dword ptr [esi + 0x18]
// 004b1c9c  894004               mov dword ptr [eax + 4], eax
// 004b1c9f  8b4618               mov eax, dword ptr [esi + 0x18]
// 004b1ca2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004b1ca9  8900                 mov dword ptr [eax], eax
// 004b1cab  8b4618               mov eax, dword ptr [esi + 0x18]
// 004b1cae  894008               mov dword ptr [eax + 8], eax
// 004b1cb1  8b4618               mov eax, dword ptr [esi + 0x18]
// 004b1cb4  8b16                 mov edx, dword ptr [esi]
// 004b1cb6  8b08                 mov ecx, dword ptr [eax]
// 004b1cb8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004b1cbc  5f                   pop edi
// 004b1cbd  5e                   pop esi
// 004b1cbe  5d                   pop ebp
// 004b1cbf  894804               mov dword ptr [eax + 4], ecx
// 004b1cc2  8910                 mov dword ptr [eax], edx
// 004b1cc4  5b                   pop ebx
// 004b1cc5  83c408               add esp, 8
// 004b1cc8  c21400               ret 0x14
// 004b1ccb  eb03                 jmp 0x4b1cd0
// 004b1ccd  8d4900               lea ecx, [ecx]
// 004b1cd0  85ff                 test edi, edi
// 004b1cd2  7406                 je 0x4b1cda
// 004b1cd4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004b1cd8  7406                 je 0x4b1ce0
// 004b1cda  ffd5                 call ebp
// 004b1cdc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004b1ce0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004b1ce4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004b1ce8  741d                 je 0x4b1d07
// 004b1cea  8d4c2420             lea ecx, [esp + 0x20]
// 004b1cee  e83dc4ffff           call 0x4ae130
// 004b1cf3  53                   push ebx
// 004b1cf4  57                   push edi
// 004b1cf5  8d442418             lea eax, [esp + 0x18]
// 004b1cf9  50                   push eax
// 004b1cfa  8bce                 mov ecx, esi
// 004b1cfc  e87ff0ffff           call 0x4b0d80
// 004b1d01  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004b1d05  ebc9                 jmp 0x4b1cd0
// 004b1d07  8b36                 mov esi, dword ptr [esi]
// 004b1d09  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004b1d0d  5f                   pop edi
// 004b1d0e  8930                 mov dword ptr [eax], esi
// 004b1d10  5e                   pop esi
// 004b1d11  5d                   pop ebp
// 004b1d12  895804               mov dword ptr [eax + 4], ebx
// 004b1d15  5b                   pop ebx
// 004b1d16  83c408               add esp, 8
// 004b1d19  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
