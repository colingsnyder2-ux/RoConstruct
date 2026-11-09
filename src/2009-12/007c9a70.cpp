// from server: 100% by auto
// roc 2009-12 007c9a70  unit: RBX::ScoreHud  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c9a70
//
// 007c9a70  83ec08               sub esp, 8
// 007c9a73  53                   push ebx
// 007c9a74  55                   push ebp
// 007c9a75  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 007c9a7b  56                   push esi
// 007c9a7c  8bf1                 mov esi, ecx
// 007c9a7e  8b4618               mov eax, dword ptr [esi + 0x18]
// 007c9a81  8b18                 mov ebx, dword ptr [eax]
// 007c9a83  8b06                 mov eax, dword ptr [esi]
// 007c9a85  57                   push edi
// 007c9a86  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007c9a8a  85ff                 test edi, edi
// 007c9a8c  7404                 je 0x7c9a92
// 007c9a8e  3bf8                 cmp edi, eax
// 007c9a90  7406                 je 0x7c9a98
// 007c9a92  ffd5                 call ebp
// 007c9a94  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007c9a98  395c2424             cmp dword ptr [esp + 0x24], ebx
// 007c9a9c  7562                 jne 0x7c9b00
// 007c9a9e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007c9aa2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 007c9aa5  8b06                 mov eax, dword ptr [esi]
// 007c9aa7  85c9                 test ecx, ecx
// 007c9aa9  7404                 je 0x7c9aaf
// 007c9aab  3bc8                 cmp ecx, eax
// 007c9aad  7406                 je 0x7c9ab5
// 007c9aaf  ffd5                 call ebp
// 007c9ab1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007c9ab5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 007c9ab9  7545                 jne 0x7c9b00
// 007c9abb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007c9abe  8b5104               mov edx, dword ptr [ecx + 4]
// 007c9ac1  52                   push edx
// 007c9ac2  8bce                 mov ecx, esi
// 007c9ac4  e8f7f4ffff           call 0x7c8fc0
// 007c9ac9  8b4618               mov eax, dword ptr [esi + 0x18]
// 007c9acc  894004               mov dword ptr [eax + 4], eax
// 007c9acf  8b4618               mov eax, dword ptr [esi + 0x18]
// 007c9ad2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 007c9ad9  8900                 mov dword ptr [eax], eax
// 007c9adb  8b4618               mov eax, dword ptr [esi + 0x18]
// 007c9ade  894008               mov dword ptr [eax + 8], eax
// 007c9ae1  8b4618               mov eax, dword ptr [esi + 0x18]
// 007c9ae4  8b16                 mov edx, dword ptr [esi]
// 007c9ae6  8b08                 mov ecx, dword ptr [eax]
// 007c9ae8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007c9aec  5f                   pop edi
// 007c9aed  5e                   pop esi
// 007c9aee  5d                   pop ebp
// 007c9aef  894804               mov dword ptr [eax + 4], ecx
// 007c9af2  8910                 mov dword ptr [eax], edx
// 007c9af4  5b                   pop ebx
// 007c9af5  83c408               add esp, 8
// 007c9af8  c21400               ret 0x14
// 007c9afb  eb03                 jmp 0x7c9b00
// 007c9afd  8d4900               lea ecx, [ecx]
// 007c9b00  85ff                 test edi, edi
// 007c9b02  7406                 je 0x7c9b0a
// 007c9b04  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 007c9b08  7406                 je 0x7c9b10
// 007c9b0a  ffd5                 call ebp
// 007c9b0c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007c9b10  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 007c9b14  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 007c9b18  741d                 je 0x7c9b37
// 007c9b1a  8d4c2420             lea ecx, [esp + 0x20]
// 007c9b1e  e8cd9dd4ff           call 0x5138f0
// 007c9b23  53                   push ebx
// 007c9b24  57                   push edi
// 007c9b25  8d442418             lea eax, [esp + 0x18]
// 007c9b29  50                   push eax
// 007c9b2a  8bce                 mov ecx, esi
// 007c9b2c  e81ff1ffff           call 0x7c8c50
// 007c9b31  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007c9b35  ebc9                 jmp 0x7c9b00
// 007c9b37  8b36                 mov esi, dword ptr [esi]
// 007c9b39  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007c9b3d  5f                   pop edi
// 007c9b3e  8930                 mov dword ptr [eax], esi
// 007c9b40  5e                   pop esi
// 007c9b41  5d                   pop ebp
// 007c9b42  895804               mov dword ptr [eax + 4], ebx
// 007c9b45  5b                   pop ebx
// 007c9b46  83c408               add esp, 8
// 007c9b49  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
