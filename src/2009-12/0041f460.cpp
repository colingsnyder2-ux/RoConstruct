// from server: 100% by auto
// roc 2009-12 0041f460  unit: CSelectionTreeCtrl  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0041f460
//
// 0041f460  83ec08               sub esp, 8
// 0041f463  53                   push ebx
// 0041f464  55                   push ebp
// 0041f465  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 0041f46b  56                   push esi
// 0041f46c  8bf1                 mov esi, ecx
// 0041f46e  8b4618               mov eax, dword ptr [esi + 0x18]
// 0041f471  8b18                 mov ebx, dword ptr [eax]
// 0041f473  8b06                 mov eax, dword ptr [esi]
// 0041f475  57                   push edi
// 0041f476  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0041f47a  85ff                 test edi, edi
// 0041f47c  7404                 je 0x41f482
// 0041f47e  3bf8                 cmp edi, eax
// 0041f480  7406                 je 0x41f488
// 0041f482  ffd5                 call ebp
// 0041f484  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0041f488  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0041f48c  7562                 jne 0x41f4f0
// 0041f48e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0041f492  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 0041f495  8b06                 mov eax, dword ptr [esi]
// 0041f497  85c9                 test ecx, ecx
// 0041f499  7404                 je 0x41f49f
// 0041f49b  3bc8                 cmp ecx, eax
// 0041f49d  7406                 je 0x41f4a5
// 0041f49f  ffd5                 call ebp
// 0041f4a1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0041f4a5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 0041f4a9  7545                 jne 0x41f4f0
// 0041f4ab  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0041f4ae  8b5104               mov edx, dword ptr [ecx + 4]
// 0041f4b1  52                   push edx
// 0041f4b2  8bce                 mov ecx, esi
// 0041f4b4  e8b7f2ffff           call 0x41e770
// 0041f4b9  8b4618               mov eax, dword ptr [esi + 0x18]
// 0041f4bc  894004               mov dword ptr [eax + 4], eax
// 0041f4bf  8b4618               mov eax, dword ptr [esi + 0x18]
// 0041f4c2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0041f4c9  8900                 mov dword ptr [eax], eax
// 0041f4cb  8b4618               mov eax, dword ptr [esi + 0x18]
// 0041f4ce  894008               mov dword ptr [eax + 8], eax
// 0041f4d1  8b4618               mov eax, dword ptr [esi + 0x18]
// 0041f4d4  8b16                 mov edx, dword ptr [esi]
// 0041f4d6  8b08                 mov ecx, dword ptr [eax]
// 0041f4d8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0041f4dc  5f                   pop edi
// 0041f4dd  5e                   pop esi
// 0041f4de  5d                   pop ebp
// 0041f4df  894804               mov dword ptr [eax + 4], ecx
// 0041f4e2  8910                 mov dword ptr [eax], edx
// 0041f4e4  5b                   pop ebx
// 0041f4e5  83c408               add esp, 8
// 0041f4e8  c21400               ret 0x14
// 0041f4eb  eb03                 jmp 0x41f4f0
// 0041f4ed  8d4900               lea ecx, [ecx]
// 0041f4f0  85ff                 test edi, edi
// 0041f4f2  7406                 je 0x41f4fa
// 0041f4f4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 0041f4f8  7406                 je 0x41f500
// 0041f4fa  ffd5                 call ebp
// 0041f4fc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0041f500  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0041f504  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 0041f508  741d                 je 0x41f527
// 0041f50a  8d4c2420             lea ecx, [esp + 0x20]
// 0041f50e  e8dddb2800           call 0x6ad0f0
// 0041f513  53                   push ebx
// 0041f514  57                   push edi
// 0041f515  8d442418             lea eax, [esp + 0x18]
// 0041f519  50                   push eax
// 0041f51a  8bce                 mov ecx, esi
// 0041f51c  e83ffcffff           call 0x41f160
// 0041f521  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0041f525  ebc9                 jmp 0x41f4f0
// 0041f527  8b36                 mov esi, dword ptr [esi]
// 0041f529  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0041f52d  5f                   pop edi
// 0041f52e  8930                 mov dword ptr [eax], esi
// 0041f530  5e                   pop esi
// 0041f531  5d                   pop ebp
// 0041f532  895804               mov dword ptr [eax + 4], ebx
// 0041f535  5b                   pop ebx
// 0041f536  83c408               add esp, 8
// 0041f539  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
