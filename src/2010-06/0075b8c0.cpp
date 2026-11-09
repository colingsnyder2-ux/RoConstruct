// from server: 100% by auto
// roc 2010-06 0075b8c0  unit: RBX::ParallelRampPoly  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0075b8c0
//
// 0075b8c0  83ec08               sub esp, 8
// 0075b8c3  53                   push ebx
// 0075b8c4  55                   push ebp
// 0075b8c5  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 0075b8cb  56                   push esi
// 0075b8cc  8bf1                 mov esi, ecx
// 0075b8ce  8b4618               mov eax, dword ptr [esi + 0x18]
// 0075b8d1  8b18                 mov ebx, dword ptr [eax]
// 0075b8d3  8b06                 mov eax, dword ptr [esi]
// 0075b8d5  57                   push edi
// 0075b8d6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0075b8da  85ff                 test edi, edi
// 0075b8dc  7404                 je 0x75b8e2
// 0075b8de  3bf8                 cmp edi, eax
// 0075b8e0  7406                 je 0x75b8e8
// 0075b8e2  ffd5                 call ebp
// 0075b8e4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0075b8e8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0075b8ec  7562                 jne 0x75b950
// 0075b8ee  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0075b8f2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 0075b8f5  8b06                 mov eax, dword ptr [esi]
// 0075b8f7  85c9                 test ecx, ecx
// 0075b8f9  7404                 je 0x75b8ff
// 0075b8fb  3bc8                 cmp ecx, eax
// 0075b8fd  7406                 je 0x75b905
// 0075b8ff  ffd5                 call ebp
// 0075b901  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0075b905  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 0075b909  7545                 jne 0x75b950
// 0075b90b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0075b90e  8b5104               mov edx, dword ptr [ecx + 4]
// 0075b911  52                   push edx
// 0075b912  8bce                 mov ecx, esi
// 0075b914  e8e72de3ff           call 0x58e700
// 0075b919  8b4618               mov eax, dword ptr [esi + 0x18]
// 0075b91c  894004               mov dword ptr [eax + 4], eax
// 0075b91f  8b4618               mov eax, dword ptr [esi + 0x18]
// 0075b922  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0075b929  8900                 mov dword ptr [eax], eax
// 0075b92b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0075b92e  894008               mov dword ptr [eax + 8], eax
// 0075b931  8b4618               mov eax, dword ptr [esi + 0x18]
// 0075b934  8b16                 mov edx, dword ptr [esi]
// 0075b936  8b08                 mov ecx, dword ptr [eax]
// 0075b938  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0075b93c  5f                   pop edi
// 0075b93d  5e                   pop esi
// 0075b93e  5d                   pop ebp
// 0075b93f  894804               mov dword ptr [eax + 4], ecx
// 0075b942  8910                 mov dword ptr [eax], edx
// 0075b944  5b                   pop ebx
// 0075b945  83c408               add esp, 8
// 0075b948  c21400               ret 0x14
// 0075b94b  eb03                 jmp 0x75b950
// 0075b94d  8d4900               lea ecx, [ecx]
// 0075b950  85ff                 test edi, edi
// 0075b952  7406                 je 0x75b95a
// 0075b954  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 0075b958  7406                 je 0x75b960
// 0075b95a  ffd5                 call ebp
// 0075b95c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0075b960  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0075b964  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 0075b968  741d                 je 0x75b987
// 0075b96a  8d4c2420             lea ecx, [esp + 0x20]
// 0075b96e  e85d29e3ff           call 0x58e2d0
// 0075b973  53                   push ebx
// 0075b974  57                   push edi
// 0075b975  8d442418             lea eax, [esp + 0x18]
// 0075b979  50                   push eax
// 0075b97a  8bce                 mov ecx, esi
// 0075b97c  e86ffcffff           call 0x75b5f0
// 0075b981  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0075b985  ebc9                 jmp 0x75b950
// 0075b987  8b36                 mov esi, dword ptr [esi]
// 0075b989  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0075b98d  5f                   pop edi
// 0075b98e  8930                 mov dword ptr [eax], esi
// 0075b990  5e                   pop esi
// 0075b991  5d                   pop ebp
// 0075b992  895804               mov dword ptr [eax + 4], ebx
// 0075b995  5b                   pop ebx
// 0075b996  83c408               add esp, 8
// 0075b999  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
