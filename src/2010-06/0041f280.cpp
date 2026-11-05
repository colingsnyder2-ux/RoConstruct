// from server: 100% by auto
// roc 2010-06 0041f280  unit: CSelectionTreeCtrl  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0041f280
//
// 0041f280  83ec08               sub esp, 8
// 0041f283  53                   push ebx
// 0041f284  55                   push ebp
// 0041f285  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 0041f28b  56                   push esi
// 0041f28c  8bf1                 mov esi, ecx
// 0041f28e  8b4618               mov eax, dword ptr [esi + 0x18]
// 0041f291  8b18                 mov ebx, dword ptr [eax]
// 0041f293  8b06                 mov eax, dword ptr [esi]
// 0041f295  57                   push edi
// 0041f296  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0041f29a  85ff                 test edi, edi
// 0041f29c  7404                 je 0x41f2a2
// 0041f29e  3bf8                 cmp edi, eax
// 0041f2a0  7406                 je 0x41f2a8
// 0041f2a2  ffd5                 call ebp
// 0041f2a4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0041f2a8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0041f2ac  7562                 jne 0x41f310
// 0041f2ae  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0041f2b2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 0041f2b5  8b06                 mov eax, dword ptr [esi]
// 0041f2b7  85c9                 test ecx, ecx
// 0041f2b9  7404                 je 0x41f2bf
// 0041f2bb  3bc8                 cmp ecx, eax
// 0041f2bd  7406                 je 0x41f2c5
// 0041f2bf  ffd5                 call ebp
// 0041f2c1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0041f2c5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 0041f2c9  7545                 jne 0x41f310
// 0041f2cb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0041f2ce  8b5104               mov edx, dword ptr [ecx + 4]
// 0041f2d1  52                   push edx
// 0041f2d2  8bce                 mov ecx, esi
// 0041f2d4  e8d7f5ffff           call 0x41e8b0
// 0041f2d9  8b4618               mov eax, dword ptr [esi + 0x18]
// 0041f2dc  894004               mov dword ptr [eax + 4], eax
// 0041f2df  8b4618               mov eax, dword ptr [esi + 0x18]
// 0041f2e2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0041f2e9  8900                 mov dword ptr [eax], eax
// 0041f2eb  8b4618               mov eax, dword ptr [esi + 0x18]
// 0041f2ee  894008               mov dword ptr [eax + 8], eax
// 0041f2f1  8b4618               mov eax, dword ptr [esi + 0x18]
// 0041f2f4  8b16                 mov edx, dword ptr [esi]
// 0041f2f6  8b08                 mov ecx, dword ptr [eax]
// 0041f2f8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0041f2fc  5f                   pop edi
// 0041f2fd  5e                   pop esi
// 0041f2fe  5d                   pop ebp
// 0041f2ff  894804               mov dword ptr [eax + 4], ecx
// 0041f302  8910                 mov dword ptr [eax], edx
// 0041f304  5b                   pop ebx
// 0041f305  83c408               add esp, 8
// 0041f308  c21400               ret 0x14
// 0041f30b  eb03                 jmp 0x41f310
// 0041f30d  8d4900               lea ecx, [ecx]
// 0041f310  85ff                 test edi, edi
// 0041f312  7406                 je 0x41f31a
// 0041f314  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 0041f318  7406                 je 0x41f320
// 0041f31a  ffd5                 call ebp
// 0041f31c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0041f320  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0041f324  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 0041f328  741d                 je 0x41f347
// 0041f32a  8d4c2420             lea ecx, [esp + 0x20]
// 0041f32e  e8ad862c00           call 0x6e79e0
// 0041f333  53                   push ebx
// 0041f334  57                   push edi
// 0041f335  8d442418             lea eax, [esp + 0x18]
// 0041f339  50                   push eax
// 0041f33a  8bce                 mov ecx, esi
// 0041f33c  e83ffcffff           call 0x41ef80
// 0041f341  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0041f345  ebc9                 jmp 0x41f310
// 0041f347  8b36                 mov esi, dword ptr [esi]
// 0041f349  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0041f34d  5f                   pop edi
// 0041f34e  8930                 mov dword ptr [eax], esi
// 0041f350  5e                   pop esi
// 0041f351  5d                   pop ebp
// 0041f352  895804               mov dword ptr [eax + 4], ebx
// 0041f355  5b                   pop ebx
// 0041f356  83c408               add esp, 8
// 0041f359  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
