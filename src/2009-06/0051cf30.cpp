// from server: 100% by auto
// roc 2009-06 0051cf30  unit: RBX::G3DTexture  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0051cf30
//
// 0051cf30  83ec08               sub esp, 8
// 0051cf33  53                   push ebx
// 0051cf34  55                   push ebp
// 0051cf35  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 0051cf3b  56                   push esi
// 0051cf3c  8bf1                 mov esi, ecx
// 0051cf3e  8b4618               mov eax, dword ptr [esi + 0x18]
// 0051cf41  8b18                 mov ebx, dword ptr [eax]
// 0051cf43  8b06                 mov eax, dword ptr [esi]
// 0051cf45  57                   push edi
// 0051cf46  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0051cf4a  85ff                 test edi, edi
// 0051cf4c  7404                 je 0x51cf52
// 0051cf4e  3bf8                 cmp edi, eax
// 0051cf50  7406                 je 0x51cf58
// 0051cf52  ffd5                 call ebp
// 0051cf54  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0051cf58  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0051cf5c  7562                 jne 0x51cfc0
// 0051cf5e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0051cf62  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 0051cf65  8b06                 mov eax, dword ptr [esi]
// 0051cf67  85c9                 test ecx, ecx
// 0051cf69  7404                 je 0x51cf6f
// 0051cf6b  3bc8                 cmp ecx, eax
// 0051cf6d  7406                 je 0x51cf75
// 0051cf6f  ffd5                 call ebp
// 0051cf71  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0051cf75  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 0051cf79  7545                 jne 0x51cfc0
// 0051cf7b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0051cf7e  8b5104               mov edx, dword ptr [ecx + 4]
// 0051cf81  52                   push edx
// 0051cf82  8bce                 mov ecx, esi
// 0051cf84  e837f2ffff           call 0x51c1c0
// 0051cf89  8b4618               mov eax, dword ptr [esi + 0x18]
// 0051cf8c  894004               mov dword ptr [eax + 4], eax
// 0051cf8f  8b4618               mov eax, dword ptr [esi + 0x18]
// 0051cf92  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0051cf99  8900                 mov dword ptr [eax], eax
// 0051cf9b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0051cf9e  894008               mov dword ptr [eax + 8], eax
// 0051cfa1  8b4618               mov eax, dword ptr [esi + 0x18]
// 0051cfa4  8b16                 mov edx, dword ptr [esi]
// 0051cfa6  8b08                 mov ecx, dword ptr [eax]
// 0051cfa8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0051cfac  5f                   pop edi
// 0051cfad  5e                   pop esi
// 0051cfae  5d                   pop ebp
// 0051cfaf  894804               mov dword ptr [eax + 4], ecx
// 0051cfb2  8910                 mov dword ptr [eax], edx
// 0051cfb4  5b                   pop ebx
// 0051cfb5  83c408               add esp, 8
// 0051cfb8  c21400               ret 0x14
// 0051cfbb  eb03                 jmp 0x51cfc0
// 0051cfbd  8d4900               lea ecx, [ecx]
// 0051cfc0  85ff                 test edi, edi
// 0051cfc2  7406                 je 0x51cfca
// 0051cfc4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 0051cfc8  7406                 je 0x51cfd0
// 0051cfca  ffd5                 call ebp
// 0051cfcc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0051cfd0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0051cfd4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 0051cfd8  741d                 je 0x51cff7
// 0051cfda  8d4c2420             lea ecx, [esp + 0x20]
// 0051cfde  e82d9bffff           call 0x516b10
// 0051cfe3  53                   push ebx
// 0051cfe4  57                   push edi
// 0051cfe5  8d442418             lea eax, [esp + 0x18]
// 0051cfe9  50                   push eax
// 0051cfea  8bce                 mov ecx, esi
// 0051cfec  e8afeeffff           call 0x51bea0
// 0051cff1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0051cff5  ebc9                 jmp 0x51cfc0
// 0051cff7  8b36                 mov esi, dword ptr [esi]
// 0051cff9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0051cffd  5f                   pop edi
// 0051cffe  8930                 mov dword ptr [eax], esi
// 0051d000  5e                   pop esi
// 0051d001  5d                   pop ebp
// 0051d002  895804               mov dword ptr [eax + 4], ebx
// 0051d005  5b                   pop ebx
// 0051d006  83c408               add esp, 8
// 0051d009  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
