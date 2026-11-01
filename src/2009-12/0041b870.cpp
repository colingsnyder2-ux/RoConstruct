// from server: 100% by auto
// roc 2009-12 0041b870  unit: CInstanceRecord  size: 352 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0041b870
//
// 0041b870  8b542404             mov edx, dword ptr [esp + 4]
// 0041b874  83ec08               sub esp, 8
// 0041b877  53                   push ebx
// 0041b878  8bd9                 mov ebx, ecx
// 0041b87a  8b4314               mov eax, dword ptr [ebx + 0x14]
// 0041b87d  b955555515           mov ecx, 0x15555555
// 0041b882  2bc8                 sub ecx, eax
// 0041b884  3bca                 cmp ecx, edx
// 0041b886  7305                 jae 0x41b88d
// 0041b888  e8c3172a00           call 0x6bd050
// 0041b88d  8bc8                 mov ecx, eax
// 0041b88f  d1e9                 shr ecx, 1
// 0041b891  83f908               cmp ecx, 8
// 0041b894  7305                 jae 0x41b89b
// 0041b896  b908000000           mov ecx, 8
// 0041b89b  55                   push ebp
// 0041b89c  56                   push esi
// 0041b89d  57                   push edi
// 0041b89e  3bd1                 cmp edx, ecx
// 0041b8a0  7311                 jae 0x41b8b3
// 0041b8a2  be55555515           mov esi, 0x15555555
// 0041b8a7  2bf1                 sub esi, ecx
// 0041b8a9  3bc6                 cmp eax, esi
// 0041b8ab  7706                 ja 0x41b8b3
// 0041b8ad  8bd1                 mov edx, ecx
// 0041b8af  8954241c             mov dword ptr [esp + 0x1c], edx
// 0041b8b3  8b7318               mov esi, dword ptr [ebx + 0x18]
// 0041b8b6  03c2                 add eax, edx
// 0041b8b8  6a00                 push 0
// 0041b8ba  50                   push eax
// 0041b8bb  89742418             mov dword ptr [esp + 0x18], esi
// 0041b8bf  e87c500100           call 0x430940
// 0041b8c4  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 0041b8c7  8944241c             mov dword ptr [esp + 0x1c], eax
// 0041b8cb  03f6                 add esi, esi
// 0041b8cd  03f6                 add esi, esi
// 0041b8cf  8d3c06               lea edi, [esi + eax]
// 0041b8d2  8b4314               mov eax, dword ptr [ebx + 0x14]
// 0041b8d5  03c0                 add eax, eax
// 0041b8d7  03c0                 add eax, eax
// 0041b8d9  8d140e               lea edx, [esi + ecx]
// 0041b8dc  2bc2                 sub eax, edx
// 0041b8de  03c1                 add eax, ecx
// 0041b8e0  c1f802               sar eax, 2
// 0041b8e3  83c408               add esp, 8
// 0041b8e6  8d0c8500000000       lea ecx, [eax*4]
// 0041b8ed  8d2c39               lea ebp, [ecx + edi]
// 0041b8f0  85c0                 test eax, eax
// 0041b8f2  760d                 jbe 0x41b901
// 0041b8f4  51                   push ecx
// 0041b8f5  52                   push edx
// 0041b8f6  51                   push ecx
// 0041b8f7  57                   push edi
// 0041b8f8  ff15c0b79800         call dword ptr [0x98b7c0]
// 0041b8fe  83c410               add esp, 0x10
// 0041b901  8b542410             mov edx, dword ptr [esp + 0x10]
// 0041b905  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0041b909  3bd0                 cmp edx, eax
// 0041b90b  7743                 ja 0x41b950
// 0041b90d  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0041b910  c1fe02               sar esi, 2
// 0041b913  8d0cb500000000       lea ecx, [esi*4]
// 0041b91a  8d3c29               lea edi, [ecx + ebp]
// 0041b91d  85f6                 test esi, esi
// 0041b91f  7611                 jbe 0x41b932
// 0041b921  51                   push ecx
// 0041b922  50                   push eax
// 0041b923  51                   push ecx
// 0041b924  55                   push ebp
// 0041b925  ff15c0b79800         call dword ptr [0x98b7c0]
// 0041b92b  8b542420             mov edx, dword ptr [esp + 0x20]
// 0041b92f  83c410               add esp, 0x10
// 0041b932  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0041b936  2bca                 sub ecx, edx
// 0041b938  7408                 je 0x41b942
// 0041b93a  8b542410             mov edx, dword ptr [esp + 0x10]
// 0041b93e  33c0                 xor eax, eax
// 0041b940  f3ab                 rep stosd dword ptr es:[edi], eax
// 0041b942  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0041b946  85d2                 test edx, edx
// 0041b948  7662                 jbe 0x41b9ac
// 0041b94a  8bca                 mov ecx, edx
// 0041b94c  8bfd                 mov edi, ebp
// 0041b94e  eb58                 jmp 0x41b9a8
// 0041b950  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 0041b953  8d3c8500000000       lea edi, [eax*4]
// 0041b95a  8bc7                 mov eax, edi
// 0041b95c  c1f802               sar eax, 2
// 0041b95f  85c0                 test eax, eax
// 0041b961  7611                 jbe 0x41b974
// 0041b963  03c0                 add eax, eax
// 0041b965  03c0                 add eax, eax
// 0041b967  50                   push eax
// 0041b968  51                   push ecx
// 0041b969  50                   push eax
// 0041b96a  55                   push ebp
// 0041b96b  ff15c0b79800         call dword ptr [0x98b7c0]
// 0041b971  83c410               add esp, 0x10
// 0041b974  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0041b977  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0041b97b  8d0c07               lea ecx, [edi + eax]
// 0041b97e  2bf1                 sub esi, ecx
// 0041b980  03f0                 add esi, eax
// 0041b982  c1fe02               sar esi, 2
// 0041b985  8d04b500000000       lea eax, [esi*4]
// 0041b98c  8d3c28               lea edi, [eax + ebp]
// 0041b98f  85f6                 test esi, esi
// 0041b991  760d                 jbe 0x41b9a0
// 0041b993  50                   push eax
// 0041b994  51                   push ecx
// 0041b995  50                   push eax
// 0041b996  55                   push ebp
// 0041b997  ff15c0b79800         call dword ptr [0x98b7c0]
// 0041b99d  83c410               add esp, 0x10
// 0041b9a0  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0041b9a4  85c9                 test ecx, ecx
// 0041b9a6  7604                 jbe 0x41b9ac
// 0041b9a8  33c0                 xor eax, eax
// 0041b9aa  f3ab                 rep stosd dword ptr es:[edi], eax
// 0041b9ac  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0041b9af  85c0                 test eax, eax
// 0041b9b1  7409                 je 0x41b9bc
// 0041b9b3  50                   push eax
// 0041b9b4  e8a17e3d00           call 0x7f385a
// 0041b9b9  83c404               add esp, 4
// 0041b9bc  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0041b9c0  015314               add dword ptr [ebx + 0x14], edx
// 0041b9c3  5f                   pop edi
// 0041b9c4  5e                   pop esi
// 0041b9c5  896b10               mov dword ptr [ebx + 0x10], ebp
// 0041b9c8  5d                   pop ebp
// 0041b9c9  5b                   pop ebx
// 0041b9ca  83c408               add esp, 8
// 0041b9cd  c20400               ret 4
// standard library deque<pod12> (function ?_Growmap@?$deque@UE@@V?$allocator@UE@@@std@@@std@@IAEXI@Z)

// stl: deque<pod12>
struct E { int v[3]; };
#include <deque>
template class std::deque<E>;
