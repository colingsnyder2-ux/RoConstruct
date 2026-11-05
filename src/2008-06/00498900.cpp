// from server: 100% by auto
// roc 2008-06 00498900  unit: RBX::Network::VPlayers::?$SignalDesc  size: 352 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00498900
//
// 00498900  8b542404             mov edx, dword ptr [esp + 4]
// 00498904  83ec08               sub esp, 8
// 00498907  53                   push ebx
// 00498908  8bd9                 mov ebx, ecx
// 0049890a  8b4314               mov eax, dword ptr [ebx + 0x14]
// 0049890d  b9ffffff03           mov ecx, 0x3ffffff
// 00498912  2bc8                 sub ecx, eax
// 00498914  3bca                 cmp ecx, edx
// 00498916  7305                 jae 0x49891d
// 00498918  e8f3e00700           call 0x516a10
// 0049891d  8bc8                 mov ecx, eax
// 0049891f  d1e9                 shr ecx, 1
// 00498921  83f908               cmp ecx, 8
// 00498924  7305                 jae 0x49892b
// 00498926  b908000000           mov ecx, 8
// 0049892b  55                   push ebp
// 0049892c  56                   push esi
// 0049892d  57                   push edi
// 0049892e  3bd1                 cmp edx, ecx
// 00498930  7311                 jae 0x498943
// 00498932  beffffff03           mov esi, 0x3ffffff
// 00498937  2bf1                 sub esi, ecx
// 00498939  3bc6                 cmp eax, esi
// 0049893b  7706                 ja 0x498943
// 0049893d  8bd1                 mov edx, ecx
// 0049893f  8954241c             mov dword ptr [esp + 0x1c], edx
// 00498943  8b7318               mov esi, dword ptr [ebx + 0x18]
// 00498946  03c2                 add eax, edx
// 00498948  6a00                 push 0
// 0049894a  50                   push eax
// 0049894b  89742418             mov dword ptr [esp + 0x18], esi
// 0049894f  e8fc81f8ff           call 0x420b50
// 00498954  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 00498957  8944241c             mov dword ptr [esp + 0x1c], eax
// 0049895b  03f6                 add esi, esi
// 0049895d  03f6                 add esi, esi
// 0049895f  8d3c06               lea edi, [esi + eax]
// 00498962  8b4314               mov eax, dword ptr [ebx + 0x14]
// 00498965  03c0                 add eax, eax
// 00498967  03c0                 add eax, eax
// 00498969  8d140e               lea edx, [esi + ecx]
// 0049896c  2bc2                 sub eax, edx
// 0049896e  03c1                 add eax, ecx
// 00498970  c1f802               sar eax, 2
// 00498973  83c408               add esp, 8
// 00498976  8d0c8500000000       lea ecx, [eax*4]
// 0049897d  8d2c39               lea ebp, [ecx + edi]
// 00498980  85c0                 test eax, eax
// 00498982  760d                 jbe 0x498991
// 00498984  51                   push ecx
// 00498985  52                   push edx
// 00498986  51                   push ecx
// 00498987  57                   push edi
// 00498988  ff1550288000         call dword ptr [0x802850]
// 0049898e  83c410               add esp, 0x10
// 00498991  8b542410             mov edx, dword ptr [esp + 0x10]
// 00498995  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00498999  3bd0                 cmp edx, eax
// 0049899b  7743                 ja 0x4989e0
// 0049899d  8b4310               mov eax, dword ptr [ebx + 0x10]
// 004989a0  c1fe02               sar esi, 2
// 004989a3  8d0cb500000000       lea ecx, [esi*4]
// 004989aa  8d3c29               lea edi, [ecx + ebp]
// 004989ad  85f6                 test esi, esi
// 004989af  7611                 jbe 0x4989c2
// 004989b1  51                   push ecx
// 004989b2  50                   push eax
// 004989b3  51                   push ecx
// 004989b4  55                   push ebp
// 004989b5  ff1550288000         call dword ptr [0x802850]
// 004989bb  8b542420             mov edx, dword ptr [esp + 0x20]
// 004989bf  83c410               add esp, 0x10
// 004989c2  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004989c6  2bca                 sub ecx, edx
// 004989c8  7408                 je 0x4989d2
// 004989ca  8b542410             mov edx, dword ptr [esp + 0x10]
// 004989ce  33c0                 xor eax, eax
// 004989d0  f3ab                 rep stosd dword ptr es:[edi], eax
// 004989d2  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 004989d6  85d2                 test edx, edx
// 004989d8  7662                 jbe 0x498a3c
// 004989da  8bca                 mov ecx, edx
// 004989dc  8bfd                 mov edi, ebp
// 004989de  eb58                 jmp 0x498a38
// 004989e0  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 004989e3  8d3c8500000000       lea edi, [eax*4]
// 004989ea  8bc7                 mov eax, edi
// 004989ec  c1f802               sar eax, 2
// 004989ef  85c0                 test eax, eax
// 004989f1  7611                 jbe 0x498a04
// 004989f3  03c0                 add eax, eax
// 004989f5  03c0                 add eax, eax
// 004989f7  50                   push eax
// 004989f8  51                   push ecx
// 004989f9  50                   push eax
// 004989fa  55                   push ebp
// 004989fb  ff1550288000         call dword ptr [0x802850]
// 00498a01  83c410               add esp, 0x10
// 00498a04  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00498a07  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00498a0b  8d0c07               lea ecx, [edi + eax]
// 00498a0e  2bf1                 sub esi, ecx
// 00498a10  03f0                 add esi, eax
// 00498a12  c1fe02               sar esi, 2
// 00498a15  8d04b500000000       lea eax, [esi*4]
// 00498a1c  8d3c28               lea edi, [eax + ebp]
// 00498a1f  85f6                 test esi, esi
// 00498a21  760d                 jbe 0x498a30
// 00498a23  50                   push eax
// 00498a24  51                   push ecx
// 00498a25  50                   push eax
// 00498a26  55                   push ebp
// 00498a27  ff1550288000         call dword ptr [0x802850]
// 00498a2d  83c410               add esp, 0x10
// 00498a30  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00498a34  85c9                 test ecx, ecx
// 00498a36  7604                 jbe 0x498a3c
// 00498a38  33c0                 xor eax, eax
// 00498a3a  f3ab                 rep stosd dword ptr es:[edi], eax
// 00498a3c  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00498a3f  85c0                 test eax, eax
// 00498a41  7409                 je 0x498a4c
// 00498a43  50                   push eax
// 00498a44  e8317c2000           call 0x6a067a
// 00498a49  83c404               add esp, 4
// 00498a4c  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00498a50  015314               add dword ptr [ebx + 0x14], edx
// 00498a53  5f                   pop edi
// 00498a54  5e                   pop esi
// 00498a55  896b10               mov dword ptr [ebx + 0x10], ebp
// 00498a58  5d                   pop ebp
// 00498a59  5b                   pop ebx
// 00498a5a  83c408               add esp, 8
// 00498a5d  c20400               ret 4
// standard library deque<pod64> (function ?_Growmap@?$deque@UE@@V?$allocator@UE@@@std@@@std@@IAEXI@Z)

// stl: deque<pod64>
struct E { int v[16]; };
#include <deque>
template class std::deque<E>;
