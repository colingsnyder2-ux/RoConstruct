// from server: 100% by auto
// roc 2009-12 004aef50  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 352 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004aef50
//
// 004aef50  8b542404             mov edx, dword ptr [esp + 4]
// 004aef54  83ec08               sub esp, 8
// 004aef57  53                   push ebx
// 004aef58  8bd9                 mov ebx, ecx
// 004aef5a  8b4314               mov eax, dword ptr [ebx + 0x14]
// 004aef5d  b9ffffff03           mov ecx, 0x3ffffff
// 004aef62  2bc8                 sub ecx, eax
// 004aef64  3bca                 cmp ecx, edx
// 004aef66  7305                 jae 0x4aef6d
// 004aef68  e8e3e02000           call 0x6bd050
// 004aef6d  8bc8                 mov ecx, eax
// 004aef6f  d1e9                 shr ecx, 1
// 004aef71  83f908               cmp ecx, 8
// 004aef74  7305                 jae 0x4aef7b
// 004aef76  b908000000           mov ecx, 8
// 004aef7b  55                   push ebp
// 004aef7c  56                   push esi
// 004aef7d  57                   push edi
// 004aef7e  3bd1                 cmp edx, ecx
// 004aef80  7311                 jae 0x4aef93
// 004aef82  beffffff03           mov esi, 0x3ffffff
// 004aef87  2bf1                 sub esi, ecx
// 004aef89  3bc6                 cmp eax, esi
// 004aef8b  7706                 ja 0x4aef93
// 004aef8d  8bd1                 mov edx, ecx
// 004aef8f  8954241c             mov dword ptr [esp + 0x1c], edx
// 004aef93  8b7318               mov esi, dword ptr [ebx + 0x18]
// 004aef96  03c2                 add eax, edx
// 004aef98  6a00                 push 0
// 004aef9a  50                   push eax
// 004aef9b  89742418             mov dword ptr [esp + 0x18], esi
// 004aef9f  e89c19f8ff           call 0x430940
// 004aefa4  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 004aefa7  8944241c             mov dword ptr [esp + 0x1c], eax
// 004aefab  03f6                 add esi, esi
// 004aefad  03f6                 add esi, esi
// 004aefaf  8d3c06               lea edi, [esi + eax]
// 004aefb2  8b4314               mov eax, dword ptr [ebx + 0x14]
// 004aefb5  03c0                 add eax, eax
// 004aefb7  03c0                 add eax, eax
// 004aefb9  8d140e               lea edx, [esi + ecx]
// 004aefbc  2bc2                 sub eax, edx
// 004aefbe  03c1                 add eax, ecx
// 004aefc0  c1f802               sar eax, 2
// 004aefc3  83c408               add esp, 8
// 004aefc6  8d0c8500000000       lea ecx, [eax*4]
// 004aefcd  8d2c39               lea ebp, [ecx + edi]
// 004aefd0  85c0                 test eax, eax
// 004aefd2  760d                 jbe 0x4aefe1
// 004aefd4  51                   push ecx
// 004aefd5  52                   push edx
// 004aefd6  51                   push ecx
// 004aefd7  57                   push edi
// 004aefd8  ff15c0b79800         call dword ptr [0x98b7c0]
// 004aefde  83c410               add esp, 0x10
// 004aefe1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004aefe5  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004aefe9  3bd0                 cmp edx, eax
// 004aefeb  7743                 ja 0x4af030
// 004aefed  8b4310               mov eax, dword ptr [ebx + 0x10]
// 004aeff0  c1fe02               sar esi, 2
// 004aeff3  8d0cb500000000       lea ecx, [esi*4]
// 004aeffa  8d3c29               lea edi, [ecx + ebp]
// 004aeffd  85f6                 test esi, esi
// 004aefff  7611                 jbe 0x4af012
// 004af001  51                   push ecx
// 004af002  50                   push eax
// 004af003  51                   push ecx
// 004af004  55                   push ebp
// 004af005  ff15c0b79800         call dword ptr [0x98b7c0]
// 004af00b  8b542420             mov edx, dword ptr [esp + 0x20]
// 004af00f  83c410               add esp, 0x10
// 004af012  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004af016  2bca                 sub ecx, edx
// 004af018  7408                 je 0x4af022
// 004af01a  8b542410             mov edx, dword ptr [esp + 0x10]
// 004af01e  33c0                 xor eax, eax
// 004af020  f3ab                 rep stosd dword ptr es:[edi], eax
// 004af022  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 004af026  85d2                 test edx, edx
// 004af028  7662                 jbe 0x4af08c
// 004af02a  8bca                 mov ecx, edx
// 004af02c  8bfd                 mov edi, ebp
// 004af02e  eb58                 jmp 0x4af088
// 004af030  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 004af033  8d3c8500000000       lea edi, [eax*4]
// 004af03a  8bc7                 mov eax, edi
// 004af03c  c1f802               sar eax, 2
// 004af03f  85c0                 test eax, eax
// 004af041  7611                 jbe 0x4af054
// 004af043  03c0                 add eax, eax
// 004af045  03c0                 add eax, eax
// 004af047  50                   push eax
// 004af048  51                   push ecx
// 004af049  50                   push eax
// 004af04a  55                   push ebp
// 004af04b  ff15c0b79800         call dword ptr [0x98b7c0]
// 004af051  83c410               add esp, 0x10
// 004af054  8b4310               mov eax, dword ptr [ebx + 0x10]
// 004af057  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 004af05b  8d0c07               lea ecx, [edi + eax]
// 004af05e  2bf1                 sub esi, ecx
// 004af060  03f0                 add esi, eax
// 004af062  c1fe02               sar esi, 2
// 004af065  8d04b500000000       lea eax, [esi*4]
// 004af06c  8d3c28               lea edi, [eax + ebp]
// 004af06f  85f6                 test esi, esi
// 004af071  760d                 jbe 0x4af080
// 004af073  50                   push eax
// 004af074  51                   push ecx
// 004af075  50                   push eax
// 004af076  55                   push ebp
// 004af077  ff15c0b79800         call dword ptr [0x98b7c0]
// 004af07d  83c410               add esp, 0x10
// 004af080  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004af084  85c9                 test ecx, ecx
// 004af086  7604                 jbe 0x4af08c
// 004af088  33c0                 xor eax, eax
// 004af08a  f3ab                 rep stosd dword ptr es:[edi], eax
// 004af08c  8b4310               mov eax, dword ptr [ebx + 0x10]
// 004af08f  85c0                 test eax, eax
// 004af091  7409                 je 0x4af09c
// 004af093  50                   push eax
// 004af094  e8c1473400           call 0x7f385a
// 004af099  83c404               add esp, 4
// 004af09c  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 004af0a0  015314               add dword ptr [ebx + 0x14], edx
// 004af0a3  5f                   pop edi
// 004af0a4  5e                   pop esi
// 004af0a5  896b10               mov dword ptr [ebx + 0x10], ebp
// 004af0a8  5d                   pop ebp
// 004af0a9  5b                   pop ebx
// 004af0aa  83c408               add esp, 8
// 004af0ad  c20400               ret 4
// standard library deque<pod64> (function ?_Growmap@?$deque@UE@@V?$allocator@UE@@@std@@@std@@IAEXI@Z)

// stl: deque<pod64>
struct E { int v[16]; };
#include <deque>
template class std::deque<E>;
