// from server: 100% by auto
// roc 2010-06 0061bf80  unit: RBX::Accoutrement  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0061bf80
//
// 0061bf80  83ec08               sub esp, 8
// 0061bf83  53                   push ebx
// 0061bf84  55                   push ebp
// 0061bf85  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 0061bf8b  56                   push esi
// 0061bf8c  8bf1                 mov esi, ecx
// 0061bf8e  8b4618               mov eax, dword ptr [esi + 0x18]
// 0061bf91  8b18                 mov ebx, dword ptr [eax]
// 0061bf93  8b06                 mov eax, dword ptr [esi]
// 0061bf95  57                   push edi
// 0061bf96  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0061bf9a  85ff                 test edi, edi
// 0061bf9c  7404                 je 0x61bfa2
// 0061bf9e  3bf8                 cmp edi, eax
// 0061bfa0  7406                 je 0x61bfa8
// 0061bfa2  ffd5                 call ebp
// 0061bfa4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0061bfa8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0061bfac  7562                 jne 0x61c010
// 0061bfae  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0061bfb2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 0061bfb5  8b06                 mov eax, dword ptr [esi]
// 0061bfb7  85c9                 test ecx, ecx
// 0061bfb9  7404                 je 0x61bfbf
// 0061bfbb  3bc8                 cmp ecx, eax
// 0061bfbd  7406                 je 0x61bfc5
// 0061bfbf  ffd5                 call ebp
// 0061bfc1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0061bfc5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 0061bfc9  7545                 jne 0x61c010
// 0061bfcb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0061bfce  8b5104               mov edx, dword ptr [ecx + 4]
// 0061bfd1  52                   push edx
// 0061bfd2  8bce                 mov ecx, esi
// 0061bfd4  e817f9ffff           call 0x61b8f0
// 0061bfd9  8b4618               mov eax, dword ptr [esi + 0x18]
// 0061bfdc  894004               mov dword ptr [eax + 4], eax
// 0061bfdf  8b4618               mov eax, dword ptr [esi + 0x18]
// 0061bfe2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0061bfe9  8900                 mov dword ptr [eax], eax
// 0061bfeb  8b4618               mov eax, dword ptr [esi + 0x18]
// 0061bfee  894008               mov dword ptr [eax + 8], eax
// 0061bff1  8b4618               mov eax, dword ptr [esi + 0x18]
// 0061bff4  8b16                 mov edx, dword ptr [esi]
// 0061bff6  8b08                 mov ecx, dword ptr [eax]
// 0061bff8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0061bffc  5f                   pop edi
// 0061bffd  5e                   pop esi
// 0061bffe  5d                   pop ebp
// 0061bfff  894804               mov dword ptr [eax + 4], ecx
// 0061c002  8910                 mov dword ptr [eax], edx
// 0061c004  5b                   pop ebx
// 0061c005  83c408               add esp, 8
// 0061c008  c21400               ret 0x14
// 0061c00b  eb03                 jmp 0x61c010
// 0061c00d  8d4900               lea ecx, [ecx]
// 0061c010  85ff                 test edi, edi
// 0061c012  7406                 je 0x61c01a
// 0061c014  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 0061c018  7406                 je 0x61c020
// 0061c01a  ffd5                 call ebp
// 0061c01c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0061c020  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0061c024  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 0061c028  741d                 je 0x61c047
// 0061c02a  8d4c2420             lea ecx, [esp + 0x20]
// 0061c02e  e80da22a00           call 0x8c6240
// 0061c033  53                   push ebx
// 0061c034  57                   push edi
// 0061c035  8d442418             lea eax, [esp + 0x18]
// 0061c039  50                   push eax
// 0061c03a  8bce                 mov ecx, esi
// 0061c03c  e8cff5ffff           call 0x61b610
// 0061c041  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0061c045  ebc9                 jmp 0x61c010
// 0061c047  8b36                 mov esi, dword ptr [esi]
// 0061c049  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0061c04d  5f                   pop edi
// 0061c04e  8930                 mov dword ptr [eax], esi
// 0061c050  5e                   pop esi
// 0061c051  5d                   pop ebp
// 0061c052  895804               mov dword ptr [eax + 4], ebx
// 0061c055  5b                   pop ebx
// 0061c056  83c408               add esp, 8
// 0061c059  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
