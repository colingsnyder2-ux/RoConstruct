// from server: 100% by auto
// roc 2010-06 004c5bf0  unit: RBX::VInstance::?$NonFactoryProduct  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004c5bf0
//
// 004c5bf0  83ec08               sub esp, 8
// 004c5bf3  53                   push ebx
// 004c5bf4  55                   push ebp
// 004c5bf5  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 004c5bfb  56                   push esi
// 004c5bfc  8bf1                 mov esi, ecx
// 004c5bfe  8b4618               mov eax, dword ptr [esi + 0x18]
// 004c5c01  8b18                 mov ebx, dword ptr [eax]
// 004c5c03  8b06                 mov eax, dword ptr [esi]
// 004c5c05  57                   push edi
// 004c5c06  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004c5c0a  85ff                 test edi, edi
// 004c5c0c  7404                 je 0x4c5c12
// 004c5c0e  3bf8                 cmp edi, eax
// 004c5c10  7406                 je 0x4c5c18
// 004c5c12  ffd5                 call ebp
// 004c5c14  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004c5c18  395c2424             cmp dword ptr [esp + 0x24], ebx
// 004c5c1c  7562                 jne 0x4c5c80
// 004c5c1e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004c5c22  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 004c5c25  8b06                 mov eax, dword ptr [esi]
// 004c5c27  85c9                 test ecx, ecx
// 004c5c29  7404                 je 0x4c5c2f
// 004c5c2b  3bc8                 cmp ecx, eax
// 004c5c2d  7406                 je 0x4c5c35
// 004c5c2f  ffd5                 call ebp
// 004c5c31  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004c5c35  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 004c5c39  7545                 jne 0x4c5c80
// 004c5c3b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004c5c3e  8b5104               mov edx, dword ptr [ecx + 4]
// 004c5c41  52                   push edx
// 004c5c42  8bce                 mov ecx, esi
// 004c5c44  e8f7e1ffff           call 0x4c3e40
// 004c5c49  8b4618               mov eax, dword ptr [esi + 0x18]
// 004c5c4c  894004               mov dword ptr [eax + 4], eax
// 004c5c4f  8b4618               mov eax, dword ptr [esi + 0x18]
// 004c5c52  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004c5c59  8900                 mov dword ptr [eax], eax
// 004c5c5b  8b4618               mov eax, dword ptr [esi + 0x18]
// 004c5c5e  894008               mov dword ptr [eax + 8], eax
// 004c5c61  8b4618               mov eax, dword ptr [esi + 0x18]
// 004c5c64  8b16                 mov edx, dword ptr [esi]
// 004c5c66  8b08                 mov ecx, dword ptr [eax]
// 004c5c68  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004c5c6c  5f                   pop edi
// 004c5c6d  5e                   pop esi
// 004c5c6e  5d                   pop ebp
// 004c5c6f  894804               mov dword ptr [eax + 4], ecx
// 004c5c72  8910                 mov dword ptr [eax], edx
// 004c5c74  5b                   pop ebx
// 004c5c75  83c408               add esp, 8
// 004c5c78  c21400               ret 0x14
// 004c5c7b  eb03                 jmp 0x4c5c80
// 004c5c7d  8d4900               lea ecx, [ecx]
// 004c5c80  85ff                 test edi, edi
// 004c5c82  7406                 je 0x4c5c8a
// 004c5c84  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004c5c88  7406                 je 0x4c5c90
// 004c5c8a  ffd5                 call ebp
// 004c5c8c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004c5c90  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004c5c94  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004c5c98  741d                 je 0x4c5cb7
// 004c5c9a  8d4c2420             lea ecx, [esp + 0x20]
// 004c5c9e  e80d992a00           call 0x76f5b0
// 004c5ca3  53                   push ebx
// 004c5ca4  57                   push edi
// 004c5ca5  8d442418             lea eax, [esp + 0x18]
// 004c5ca9  50                   push eax
// 004c5caa  8bce                 mov ecx, esi
// 004c5cac  e8afdeffff           call 0x4c3b60
// 004c5cb1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004c5cb5  ebc9                 jmp 0x4c5c80
// 004c5cb7  8b36                 mov esi, dword ptr [esi]
// 004c5cb9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004c5cbd  5f                   pop edi
// 004c5cbe  8930                 mov dword ptr [eax], esi
// 004c5cc0  5e                   pop esi
// 004c5cc1  5d                   pop ebp
// 004c5cc2  895804               mov dword ptr [eax + 4], ebx
// 004c5cc5  5b                   pop ebx
// 004c5cc6  83c408               add esp, 8
// 004c5cc9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
