// from server: 100% by auto
// roc 2009-12 004c4290  unit: Ogre::RbxCluster::VRbxPartBinding::?$sp_counted_impl_p  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004c4290
//
// 004c4290  83ec08               sub esp, 8
// 004c4293  53                   push ebx
// 004c4294  55                   push ebp
// 004c4295  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 004c429b  56                   push esi
// 004c429c  8bf1                 mov esi, ecx
// 004c429e  8b4618               mov eax, dword ptr [esi + 0x18]
// 004c42a1  8b18                 mov ebx, dword ptr [eax]
// 004c42a3  8b06                 mov eax, dword ptr [esi]
// 004c42a5  57                   push edi
// 004c42a6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004c42aa  85ff                 test edi, edi
// 004c42ac  7404                 je 0x4c42b2
// 004c42ae  3bf8                 cmp edi, eax
// 004c42b0  7406                 je 0x4c42b8
// 004c42b2  ffd5                 call ebp
// 004c42b4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004c42b8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 004c42bc  7562                 jne 0x4c4320
// 004c42be  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004c42c2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 004c42c5  8b06                 mov eax, dword ptr [esi]
// 004c42c7  85c9                 test ecx, ecx
// 004c42c9  7404                 je 0x4c42cf
// 004c42cb  3bc8                 cmp ecx, eax
// 004c42cd  7406                 je 0x4c42d5
// 004c42cf  ffd5                 call ebp
// 004c42d1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004c42d5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 004c42d9  7545                 jne 0x4c4320
// 004c42db  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004c42de  8b5104               mov edx, dword ptr [ecx + 4]
// 004c42e1  52                   push edx
// 004c42e2  8bce                 mov ecx, esi
// 004c42e4  e847fbffff           call 0x4c3e30
// 004c42e9  8b4618               mov eax, dword ptr [esi + 0x18]
// 004c42ec  894004               mov dword ptr [eax + 4], eax
// 004c42ef  8b4618               mov eax, dword ptr [esi + 0x18]
// 004c42f2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004c42f9  8900                 mov dword ptr [eax], eax
// 004c42fb  8b4618               mov eax, dword ptr [esi + 0x18]
// 004c42fe  894008               mov dword ptr [eax + 8], eax
// 004c4301  8b4618               mov eax, dword ptr [esi + 0x18]
// 004c4304  8b16                 mov edx, dword ptr [esi]
// 004c4306  8b08                 mov ecx, dword ptr [eax]
// 004c4308  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004c430c  5f                   pop edi
// 004c430d  5e                   pop esi
// 004c430e  5d                   pop ebp
// 004c430f  894804               mov dword ptr [eax + 4], ecx
// 004c4312  8910                 mov dword ptr [eax], edx
// 004c4314  5b                   pop ebx
// 004c4315  83c408               add esp, 8
// 004c4318  c21400               ret 0x14
// 004c431b  eb03                 jmp 0x4c4320
// 004c431d  8d4900               lea ecx, [ecx]
// 004c4320  85ff                 test edi, edi
// 004c4322  7406                 je 0x4c432a
// 004c4324  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004c4328  7406                 je 0x4c4330
// 004c432a  ffd5                 call ebp
// 004c432c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004c4330  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004c4334  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004c4338  741d                 je 0x4c4357
// 004c433a  8d4c2420             lea ecx, [esp + 0x20]
// 004c433e  e87de9ffff           call 0x4c2cc0
// 004c4343  53                   push ebx
// 004c4344  57                   push edi
// 004c4345  8d442418             lea eax, [esp + 0x18]
// 004c4349  50                   push eax
// 004c434a  8bce                 mov ecx, esi
// 004c434c  e8dff7ffff           call 0x4c3b30
// 004c4351  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004c4355  ebc9                 jmp 0x4c4320
// 004c4357  8b36                 mov esi, dword ptr [esi]
// 004c4359  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004c435d  5f                   pop edi
// 004c435e  8930                 mov dword ptr [eax], esi
// 004c4360  5e                   pop esi
// 004c4361  5d                   pop ebp
// 004c4362  895804               mov dword ptr [eax + 4], ebx
// 004c4365  5b                   pop ebx
// 004c4366  83c408               add esp, 8
// 004c4369  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
