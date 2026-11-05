// from server: 100% by auto
// roc 2009-12 006b5b80  unit: RBX::Soundscape::VSoundId::?$TypedPropertyDescriptor  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006b5b80
//
// 006b5b80  83ec08               sub esp, 8
// 006b5b83  53                   push ebx
// 006b5b84  55                   push ebp
// 006b5b85  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 006b5b8b  56                   push esi
// 006b5b8c  8bf1                 mov esi, ecx
// 006b5b8e  8b4618               mov eax, dword ptr [esi + 0x18]
// 006b5b91  8b18                 mov ebx, dword ptr [eax]
// 006b5b93  8b06                 mov eax, dword ptr [esi]
// 006b5b95  57                   push edi
// 006b5b96  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006b5b9a  85ff                 test edi, edi
// 006b5b9c  7404                 je 0x6b5ba2
// 006b5b9e  3bf8                 cmp edi, eax
// 006b5ba0  7406                 je 0x6b5ba8
// 006b5ba2  ffd5                 call ebp
// 006b5ba4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006b5ba8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 006b5bac  7562                 jne 0x6b5c10
// 006b5bae  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006b5bb2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 006b5bb5  8b06                 mov eax, dword ptr [esi]
// 006b5bb7  85c9                 test ecx, ecx
// 006b5bb9  7404                 je 0x6b5bbf
// 006b5bbb  3bc8                 cmp ecx, eax
// 006b5bbd  7406                 je 0x6b5bc5
// 006b5bbf  ffd5                 call ebp
// 006b5bc1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006b5bc5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 006b5bc9  7545                 jne 0x6b5c10
// 006b5bcb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006b5bce  8b5104               mov edx, dword ptr [ecx + 4]
// 006b5bd1  52                   push edx
// 006b5bd2  8bce                 mov ecx, esi
// 006b5bd4  e8f7f8ffff           call 0x6b54d0
// 006b5bd9  8b4618               mov eax, dword ptr [esi + 0x18]
// 006b5bdc  894004               mov dword ptr [eax + 4], eax
// 006b5bdf  8b4618               mov eax, dword ptr [esi + 0x18]
// 006b5be2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006b5be9  8900                 mov dword ptr [eax], eax
// 006b5beb  8b4618               mov eax, dword ptr [esi + 0x18]
// 006b5bee  894008               mov dword ptr [eax + 8], eax
// 006b5bf1  8b4618               mov eax, dword ptr [esi + 0x18]
// 006b5bf4  8b16                 mov edx, dword ptr [esi]
// 006b5bf6  8b08                 mov ecx, dword ptr [eax]
// 006b5bf8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006b5bfc  5f                   pop edi
// 006b5bfd  5e                   pop esi
// 006b5bfe  5d                   pop ebp
// 006b5bff  894804               mov dword ptr [eax + 4], ecx
// 006b5c02  8910                 mov dword ptr [eax], edx
// 006b5c04  5b                   pop ebx
// 006b5c05  83c408               add esp, 8
// 006b5c08  c21400               ret 0x14
// 006b5c0b  eb03                 jmp 0x6b5c10
// 006b5c0d  8d4900               lea ecx, [ecx]
// 006b5c10  85ff                 test edi, edi
// 006b5c12  7406                 je 0x6b5c1a
// 006b5c14  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 006b5c18  7406                 je 0x6b5c20
// 006b5c1a  ffd5                 call ebp
// 006b5c1c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006b5c20  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 006b5c24  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 006b5c28  741d                 je 0x6b5c47
// 006b5c2a  8d4c2420             lea ecx, [esp + 0x20]
// 006b5c2e  e86ddeffff           call 0x6b3aa0
// 006b5c33  53                   push ebx
// 006b5c34  57                   push edi
// 006b5c35  8d442418             lea eax, [esp + 0x18]
// 006b5c39  50                   push eax
// 006b5c3a  8bce                 mov ecx, esi
// 006b5c3c  e8aff5ffff           call 0x6b51f0
// 006b5c41  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006b5c45  ebc9                 jmp 0x6b5c10
// 006b5c47  8b36                 mov esi, dword ptr [esi]
// 006b5c49  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006b5c4d  5f                   pop edi
// 006b5c4e  8930                 mov dword ptr [eax], esi
// 006b5c50  5e                   pop esi
// 006b5c51  5d                   pop ebp
// 006b5c52  895804               mov dword ptr [eax + 4], ebx
// 006b5c55  5b                   pop ebx
// 006b5c56  83c408               add esp, 8
// 006b5c59  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
