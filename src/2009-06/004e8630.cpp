// from server: 100% by auto
// roc 2009-06 004e8630  unit: RBX::JointsService  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e8630
//
// 004e8630  83ec08               sub esp, 8
// 004e8633  53                   push ebx
// 004e8634  55                   push ebp
// 004e8635  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 004e863b  56                   push esi
// 004e863c  8bf1                 mov esi, ecx
// 004e863e  8b4618               mov eax, dword ptr [esi + 0x18]
// 004e8641  8b18                 mov ebx, dword ptr [eax]
// 004e8643  8b06                 mov eax, dword ptr [esi]
// 004e8645  57                   push edi
// 004e8646  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004e864a  85ff                 test edi, edi
// 004e864c  7404                 je 0x4e8652
// 004e864e  3bf8                 cmp edi, eax
// 004e8650  7406                 je 0x4e8658
// 004e8652  ffd5                 call ebp
// 004e8654  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004e8658  395c2424             cmp dword ptr [esp + 0x24], ebx
// 004e865c  7562                 jne 0x4e86c0
// 004e865e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004e8662  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 004e8665  8b06                 mov eax, dword ptr [esi]
// 004e8667  85c9                 test ecx, ecx
// 004e8669  7404                 je 0x4e866f
// 004e866b  3bc8                 cmp ecx, eax
// 004e866d  7406                 je 0x4e8675
// 004e866f  ffd5                 call ebp
// 004e8671  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004e8675  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 004e8679  7545                 jne 0x4e86c0
// 004e867b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004e867e  8b5104               mov edx, dword ptr [ecx + 4]
// 004e8681  52                   push edx
// 004e8682  8bce                 mov ecx, esi
// 004e8684  e897ebffff           call 0x4e7220
// 004e8689  8b4618               mov eax, dword ptr [esi + 0x18]
// 004e868c  894004               mov dword ptr [eax + 4], eax
// 004e868f  8b4618               mov eax, dword ptr [esi + 0x18]
// 004e8692  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004e8699  8900                 mov dword ptr [eax], eax
// 004e869b  8b4618               mov eax, dword ptr [esi + 0x18]
// 004e869e  894008               mov dword ptr [eax + 8], eax
// 004e86a1  8b4618               mov eax, dword ptr [esi + 0x18]
// 004e86a4  8b16                 mov edx, dword ptr [esi]
// 004e86a6  8b08                 mov ecx, dword ptr [eax]
// 004e86a8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004e86ac  5f                   pop edi
// 004e86ad  5e                   pop esi
// 004e86ae  5d                   pop ebp
// 004e86af  894804               mov dword ptr [eax + 4], ecx
// 004e86b2  8910                 mov dword ptr [eax], edx
// 004e86b4  5b                   pop ebx
// 004e86b5  83c408               add esp, 8
// 004e86b8  c21400               ret 0x14
// 004e86bb  eb03                 jmp 0x4e86c0
// 004e86bd  8d4900               lea ecx, [ecx]
// 004e86c0  85ff                 test edi, edi
// 004e86c2  7406                 je 0x4e86ca
// 004e86c4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004e86c8  7406                 je 0x4e86d0
// 004e86ca  ffd5                 call ebp
// 004e86cc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004e86d0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004e86d4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004e86d8  741d                 je 0x4e86f7
// 004e86da  8d4c2420             lea ecx, [esp + 0x20]
// 004e86de  e82d631500           call 0x63ea10
// 004e86e3  53                   push ebx
// 004e86e4  57                   push edi
// 004e86e5  8d442418             lea eax, [esp + 0x18]
// 004e86e9  50                   push eax
// 004e86ea  8bce                 mov ecx, esi
// 004e86ec  e85fe7ffff           call 0x4e6e50
// 004e86f1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004e86f5  ebc9                 jmp 0x4e86c0
// 004e86f7  8b36                 mov esi, dword ptr [esi]
// 004e86f9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004e86fd  5f                   pop edi
// 004e86fe  8930                 mov dword ptr [eax], esi
// 004e8700  5e                   pop esi
// 004e8701  5d                   pop ebp
// 004e8702  895804               mov dword ptr [eax + 4], ebx
// 004e8705  5b                   pop ebx
// 004e8706  83c408               add esp, 8
// 004e8709  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
