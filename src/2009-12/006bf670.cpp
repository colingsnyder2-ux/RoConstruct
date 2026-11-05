// from server: 100% by auto
// roc 2009-12 006bf670  unit: RBX::VInstance::?$NonFactoryProduct  size: 352 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006bf670
//
// 006bf670  8b542404             mov edx, dword ptr [esp + 4]
// 006bf674  83ec08               sub esp, 8
// 006bf677  53                   push ebx
// 006bf678  8bd9                 mov ebx, ecx
// 006bf67a  8b4314               mov eax, dword ptr [ebx + 0x14]
// 006bf67d  b955555505           mov ecx, 0x5555555
// 006bf682  2bc8                 sub ecx, eax
// 006bf684  3bca                 cmp ecx, edx
// 006bf686  7305                 jae 0x6bf68d
// 006bf688  e8c3d9ffff           call 0x6bd050
// 006bf68d  8bc8                 mov ecx, eax
// 006bf68f  d1e9                 shr ecx, 1
// 006bf691  83f908               cmp ecx, 8
// 006bf694  7305                 jae 0x6bf69b
// 006bf696  b908000000           mov ecx, 8
// 006bf69b  55                   push ebp
// 006bf69c  56                   push esi
// 006bf69d  57                   push edi
// 006bf69e  3bd1                 cmp edx, ecx
// 006bf6a0  7311                 jae 0x6bf6b3
// 006bf6a2  be55555505           mov esi, 0x5555555
// 006bf6a7  2bf1                 sub esi, ecx
// 006bf6a9  3bc6                 cmp eax, esi
// 006bf6ab  7706                 ja 0x6bf6b3
// 006bf6ad  8bd1                 mov edx, ecx
// 006bf6af  8954241c             mov dword ptr [esp + 0x1c], edx
// 006bf6b3  8b7318               mov esi, dword ptr [ebx + 0x18]
// 006bf6b6  03c2                 add eax, edx
// 006bf6b8  6a00                 push 0
// 006bf6ba  50                   push eax
// 006bf6bb  89742418             mov dword ptr [esp + 0x18], esi
// 006bf6bf  e87c12d7ff           call 0x430940
// 006bf6c4  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 006bf6c7  8944241c             mov dword ptr [esp + 0x1c], eax
// 006bf6cb  03f6                 add esi, esi
// 006bf6cd  03f6                 add esi, esi
// 006bf6cf  8d3c06               lea edi, [esi + eax]
// 006bf6d2  8b4314               mov eax, dword ptr [ebx + 0x14]
// 006bf6d5  03c0                 add eax, eax
// 006bf6d7  03c0                 add eax, eax
// 006bf6d9  8d140e               lea edx, [esi + ecx]
// 006bf6dc  2bc2                 sub eax, edx
// 006bf6de  03c1                 add eax, ecx
// 006bf6e0  c1f802               sar eax, 2
// 006bf6e3  83c408               add esp, 8
// 006bf6e6  8d0c8500000000       lea ecx, [eax*4]
// 006bf6ed  8d2c39               lea ebp, [ecx + edi]
// 006bf6f0  85c0                 test eax, eax
// 006bf6f2  760d                 jbe 0x6bf701
// 006bf6f4  51                   push ecx
// 006bf6f5  52                   push edx
// 006bf6f6  51                   push ecx
// 006bf6f7  57                   push edi
// 006bf6f8  ff15c0b79800         call dword ptr [0x98b7c0]
// 006bf6fe  83c410               add esp, 0x10
// 006bf701  8b542410             mov edx, dword ptr [esp + 0x10]
// 006bf705  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006bf709  3bd0                 cmp edx, eax
// 006bf70b  7743                 ja 0x6bf750
// 006bf70d  8b4310               mov eax, dword ptr [ebx + 0x10]
// 006bf710  c1fe02               sar esi, 2
// 006bf713  8d0cb500000000       lea ecx, [esi*4]
// 006bf71a  8d3c29               lea edi, [ecx + ebp]
// 006bf71d  85f6                 test esi, esi
// 006bf71f  7611                 jbe 0x6bf732
// 006bf721  51                   push ecx
// 006bf722  50                   push eax
// 006bf723  51                   push ecx
// 006bf724  55                   push ebp
// 006bf725  ff15c0b79800         call dword ptr [0x98b7c0]
// 006bf72b  8b542420             mov edx, dword ptr [esp + 0x20]
// 006bf72f  83c410               add esp, 0x10
// 006bf732  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 006bf736  2bca                 sub ecx, edx
// 006bf738  7408                 je 0x6bf742
// 006bf73a  8b542410             mov edx, dword ptr [esp + 0x10]
// 006bf73e  33c0                 xor eax, eax
// 006bf740  f3ab                 rep stosd dword ptr es:[edi], eax
// 006bf742  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 006bf746  85d2                 test edx, edx
// 006bf748  7662                 jbe 0x6bf7ac
// 006bf74a  8bca                 mov ecx, edx
// 006bf74c  8bfd                 mov edi, ebp
// 006bf74e  eb58                 jmp 0x6bf7a8
// 006bf750  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 006bf753  8d3c8500000000       lea edi, [eax*4]
// 006bf75a  8bc7                 mov eax, edi
// 006bf75c  c1f802               sar eax, 2
// 006bf75f  85c0                 test eax, eax
// 006bf761  7611                 jbe 0x6bf774
// 006bf763  03c0                 add eax, eax
// 006bf765  03c0                 add eax, eax
// 006bf767  50                   push eax
// 006bf768  51                   push ecx
// 006bf769  50                   push eax
// 006bf76a  55                   push ebp
// 006bf76b  ff15c0b79800         call dword ptr [0x98b7c0]
// 006bf771  83c410               add esp, 0x10
// 006bf774  8b4310               mov eax, dword ptr [ebx + 0x10]
// 006bf777  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 006bf77b  8d0c07               lea ecx, [edi + eax]
// 006bf77e  2bf1                 sub esi, ecx
// 006bf780  03f0                 add esi, eax
// 006bf782  c1fe02               sar esi, 2
// 006bf785  8d04b500000000       lea eax, [esi*4]
// 006bf78c  8d3c28               lea edi, [eax + ebp]
// 006bf78f  85f6                 test esi, esi
// 006bf791  760d                 jbe 0x6bf7a0
// 006bf793  50                   push eax
// 006bf794  51                   push ecx
// 006bf795  50                   push eax
// 006bf796  55                   push ebp
// 006bf797  ff15c0b79800         call dword ptr [0x98b7c0]
// 006bf79d  83c410               add esp, 0x10
// 006bf7a0  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 006bf7a4  85c9                 test ecx, ecx
// 006bf7a6  7604                 jbe 0x6bf7ac
// 006bf7a8  33c0                 xor eax, eax
// 006bf7aa  f3ab                 rep stosd dword ptr es:[edi], eax
// 006bf7ac  8b4310               mov eax, dword ptr [ebx + 0x10]
// 006bf7af  85c0                 test eax, eax
// 006bf7b1  7409                 je 0x6bf7bc
// 006bf7b3  50                   push eax
// 006bf7b4  e8a1401300           call 0x7f385a
// 006bf7b9  83c404               add esp, 4
// 006bf7bc  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 006bf7c0  015314               add dword ptr [ebx + 0x14], edx
// 006bf7c3  5f                   pop edi
// 006bf7c4  5e                   pop esi
// 006bf7c5  896b10               mov dword ptr [ebx + 0x10], ebp
// 006bf7c8  5d                   pop ebp
// 006bf7c9  5b                   pop ebx
// 006bf7ca  83c408               add esp, 8
// 006bf7cd  c20400               ret 4
// standard library deque<pod48> (function ?_Growmap@?$deque@UE@@V?$allocator@UE@@@std@@@std@@IAEXI@Z)

// stl: deque<pod48>
struct E { int v[12]; };
#include <deque>
template class std::deque<E>;
