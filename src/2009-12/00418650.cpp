// from server: 100% by auto
// roc 2009-12 00418650  unit: RBX::VTool::?$FactoryProduct::Creator  size: 352 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00418650
//
// 00418650  8b542404             mov edx, dword ptr [esp + 4]
// 00418654  83ec08               sub esp, 8
// 00418657  53                   push ebx
// 00418658  8bd9                 mov ebx, ecx
// 0041865a  8b4314               mov eax, dword ptr [ebx + 0x14]
// 0041865d  b949922409           mov ecx, 0x9249249
// 00418662  2bc8                 sub ecx, eax
// 00418664  3bca                 cmp ecx, edx
// 00418666  7305                 jae 0x41866d
// 00418668  e8e3492a00           call 0x6bd050
// 0041866d  8bc8                 mov ecx, eax
// 0041866f  d1e9                 shr ecx, 1
// 00418671  83f908               cmp ecx, 8
// 00418674  7305                 jae 0x41867b
// 00418676  b908000000           mov ecx, 8
// 0041867b  55                   push ebp
// 0041867c  56                   push esi
// 0041867d  57                   push edi
// 0041867e  3bd1                 cmp edx, ecx
// 00418680  7311                 jae 0x418693
// 00418682  be49922409           mov esi, 0x9249249
// 00418687  2bf1                 sub esi, ecx
// 00418689  3bc6                 cmp eax, esi
// 0041868b  7706                 ja 0x418693
// 0041868d  8bd1                 mov edx, ecx
// 0041868f  8954241c             mov dword ptr [esp + 0x1c], edx
// 00418693  8b7318               mov esi, dword ptr [ebx + 0x18]
// 00418696  03c2                 add eax, edx
// 00418698  6a00                 push 0
// 0041869a  50                   push eax
// 0041869b  89742418             mov dword ptr [esp + 0x18], esi
// 0041869f  e89c820100           call 0x430940
// 004186a4  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 004186a7  8944241c             mov dword ptr [esp + 0x1c], eax
// 004186ab  03f6                 add esi, esi
// 004186ad  03f6                 add esi, esi
// 004186af  8d3c06               lea edi, [esi + eax]
// 004186b2  8b4314               mov eax, dword ptr [ebx + 0x14]
// 004186b5  03c0                 add eax, eax
// 004186b7  03c0                 add eax, eax
// 004186b9  8d140e               lea edx, [esi + ecx]
// 004186bc  2bc2                 sub eax, edx
// 004186be  03c1                 add eax, ecx
// 004186c0  c1f802               sar eax, 2
// 004186c3  83c408               add esp, 8
// 004186c6  8d0c8500000000       lea ecx, [eax*4]
// 004186cd  8d2c39               lea ebp, [ecx + edi]
// 004186d0  85c0                 test eax, eax
// 004186d2  760d                 jbe 0x4186e1
// 004186d4  51                   push ecx
// 004186d5  52                   push edx
// 004186d6  51                   push ecx
// 004186d7  57                   push edi
// 004186d8  ff15c0b79800         call dword ptr [0x98b7c0]
// 004186de  83c410               add esp, 0x10
// 004186e1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004186e5  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004186e9  3bd0                 cmp edx, eax
// 004186eb  7743                 ja 0x418730
// 004186ed  8b4310               mov eax, dword ptr [ebx + 0x10]
// 004186f0  c1fe02               sar esi, 2
// 004186f3  8d0cb500000000       lea ecx, [esi*4]
// 004186fa  8d3c29               lea edi, [ecx + ebp]
// 004186fd  85f6                 test esi, esi
// 004186ff  7611                 jbe 0x418712
// 00418701  51                   push ecx
// 00418702  50                   push eax
// 00418703  51                   push ecx
// 00418704  55                   push ebp
// 00418705  ff15c0b79800         call dword ptr [0x98b7c0]
// 0041870b  8b542420             mov edx, dword ptr [esp + 0x20]
// 0041870f  83c410               add esp, 0x10
// 00418712  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00418716  2bca                 sub ecx, edx
// 00418718  7408                 je 0x418722
// 0041871a  8b542410             mov edx, dword ptr [esp + 0x10]
// 0041871e  33c0                 xor eax, eax
// 00418720  f3ab                 rep stosd dword ptr es:[edi], eax
// 00418722  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00418726  85d2                 test edx, edx
// 00418728  7662                 jbe 0x41878c
// 0041872a  8bca                 mov ecx, edx
// 0041872c  8bfd                 mov edi, ebp
// 0041872e  eb58                 jmp 0x418788
// 00418730  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 00418733  8d3c8500000000       lea edi, [eax*4]
// 0041873a  8bc7                 mov eax, edi
// 0041873c  c1f802               sar eax, 2
// 0041873f  85c0                 test eax, eax
// 00418741  7611                 jbe 0x418754
// 00418743  03c0                 add eax, eax
// 00418745  03c0                 add eax, eax
// 00418747  50                   push eax
// 00418748  51                   push ecx
// 00418749  50                   push eax
// 0041874a  55                   push ebp
// 0041874b  ff15c0b79800         call dword ptr [0x98b7c0]
// 00418751  83c410               add esp, 0x10
// 00418754  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00418757  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0041875b  8d0c07               lea ecx, [edi + eax]
// 0041875e  2bf1                 sub esi, ecx
// 00418760  03f0                 add esi, eax
// 00418762  c1fe02               sar esi, 2
// 00418765  8d04b500000000       lea eax, [esi*4]
// 0041876c  8d3c28               lea edi, [eax + ebp]
// 0041876f  85f6                 test esi, esi
// 00418771  760d                 jbe 0x418780
// 00418773  50                   push eax
// 00418774  51                   push ecx
// 00418775  50                   push eax
// 00418776  55                   push ebp
// 00418777  ff15c0b79800         call dword ptr [0x98b7c0]
// 0041877d  83c410               add esp, 0x10
// 00418780  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00418784  85c9                 test ecx, ecx
// 00418786  7604                 jbe 0x41878c
// 00418788  33c0                 xor eax, eax
// 0041878a  f3ab                 rep stosd dword ptr es:[edi], eax
// 0041878c  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0041878f  85c0                 test eax, eax
// 00418791  7409                 je 0x41879c
// 00418793  50                   push eax
// 00418794  e8c1b03d00           call 0x7f385a
// 00418799  83c404               add esp, 4
// 0041879c  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 004187a0  015314               add dword ptr [ebx + 0x14], edx
// 004187a3  5f                   pop edi
// 004187a4  5e                   pop esi
// 004187a5  896b10               mov dword ptr [ebx + 0x10], ebp
// 004187a8  5d                   pop ebp
// 004187a9  5b                   pop ebx
// 004187aa  83c408               add esp, 8
// 004187ad  c20400               ret 4
// standard library deque<string> (function ?_Growmap@?$deque@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXI@Z)

// stl: deque<string>
#include <string>
typedef std::string E;
#include <deque>
template class std::deque<E>;
