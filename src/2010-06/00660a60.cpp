// from server: 100% by auto
// roc 2010-06 00660a60  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 349 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00660a60
//
// 00660a60  51                   push ecx
// 00660a61  8b542408             mov edx, dword ptr [esp + 8]
// 00660a65  53                   push ebx
// 00660a66  8bd9                 mov ebx, ecx
// 00660a68  8b4314               mov eax, dword ptr [ebx + 0x14]
// 00660a6b  b9ffffff0f           mov ecx, 0xfffffff
// 00660a70  2bc8                 sub ecx, eax
// 00660a72  3bca                 cmp ecx, edx
// 00660a74  7305                 jae 0x660a7b
// 00660a76  e855f3e5ff           call 0x4bfdd0
// 00660a7b  8bc8                 mov ecx, eax
// 00660a7d  d1e9                 shr ecx, 1
// 00660a7f  83f908               cmp ecx, 8
// 00660a82  7305                 jae 0x660a89
// 00660a84  b908000000           mov ecx, 8
// 00660a89  55                   push ebp
// 00660a8a  56                   push esi
// 00660a8b  57                   push edi
// 00660a8c  3bd1                 cmp edx, ecx
// 00660a8e  7311                 jae 0x660aa1
// 00660a90  beffffff0f           mov esi, 0xfffffff
// 00660a95  2bf1                 sub esi, ecx
// 00660a97  3bc6                 cmp eax, esi
// 00660a99  7706                 ja 0x660aa1
// 00660a9b  894c2418             mov dword ptr [esp + 0x18], ecx
// 00660a9f  8bd1                 mov edx, ecx
// 00660aa1  8b6b18               mov ebp, dword ptr [ebx + 0x18]
// 00660aa4  03c2                 add eax, edx
// 00660aa6  6a00                 push 0
// 00660aa8  50                   push eax
// 00660aa9  d1ed                 shr ebp, 1
// 00660aab  e860482700           call 0x8d5310
// 00660ab0  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 00660ab3  89442418             mov dword ptr [esp + 0x18], eax
// 00660ab7  8d34ad00000000       lea esi, [ebp*4]
// 00660abe  8d3c06               lea edi, [esi + eax]
// 00660ac1  8b4314               mov eax, dword ptr [ebx + 0x14]
// 00660ac4  03c0                 add eax, eax
// 00660ac6  03c0                 add eax, eax
// 00660ac8  8d140e               lea edx, [esi + ecx]
// 00660acb  2bc2                 sub eax, edx
// 00660acd  03c1                 add eax, ecx
// 00660acf  c1f802               sar eax, 2
// 00660ad2  8d0c8500000000       lea ecx, [eax*4]
// 00660ad9  83c408               add esp, 8
// 00660adc  03f9                 add edi, ecx
// 00660ade  85c0                 test eax, eax
// 00660ae0  7614                 jbe 0x660af6
// 00660ae2  51                   push ecx
// 00660ae3  52                   push edx
// 00660ae4  8b542418             mov edx, dword ptr [esp + 0x18]
// 00660ae8  51                   push ecx
// 00660ae9  8d0416               lea eax, [esi + edx]
// 00660aec  50                   push eax
// 00660aed  ff1580a89e00         call dword ptr [0x9ea880]
// 00660af3  83c410               add esp, 0x10
// 00660af6  8b442418             mov eax, dword ptr [esp + 0x18]
// 00660afa  3be8                 cmp ebp, eax
// 00660afc  773d                 ja 0x660b3b
// 00660afe  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00660b01  c1fe02               sar esi, 2
// 00660b04  8bce                 mov ecx, esi
// 00660b06  8d148d00000000       lea edx, [ecx*4]
// 00660b0d  8d343a               lea esi, [edx + edi]
// 00660b10  85c9                 test ecx, ecx
// 00660b12  760d                 jbe 0x660b21
// 00660b14  52                   push edx
// 00660b15  50                   push eax
// 00660b16  52                   push edx
// 00660b17  57                   push edi
// 00660b18  ff1580a89e00         call dword ptr [0x9ea880]
// 00660b1e  83c410               add esp, 0x10
// 00660b21  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00660b25  2bcd                 sub ecx, ebp
// 00660b27  7406                 je 0x660b2f
// 00660b29  33c0                 xor eax, eax
// 00660b2b  8bfe                 mov edi, esi
// 00660b2d  f3ab                 rep stosd dword ptr es:[edi], eax
// 00660b2f  85ed                 test ebp, ebp
// 00660b31  7664                 jbe 0x660b97
// 00660b33  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00660b37  8bcd                 mov ecx, ebp
// 00660b39  eb58                 jmp 0x660b93
// 00660b3b  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 00660b3e  8d2c8500000000       lea ebp, [eax*4]
// 00660b45  8bc5                 mov eax, ebp
// 00660b47  c1f802               sar eax, 2
// 00660b4a  85c0                 test eax, eax
// 00660b4c  7611                 jbe 0x660b5f
// 00660b4e  03c0                 add eax, eax
// 00660b50  03c0                 add eax, eax
// 00660b52  50                   push eax
// 00660b53  51                   push ecx
// 00660b54  50                   push eax
// 00660b55  57                   push edi
// 00660b56  ff1580a89e00         call dword ptr [0x9ea880]
// 00660b5c  83c410               add esp, 0x10
// 00660b5f  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00660b62  8b542410             mov edx, dword ptr [esp + 0x10]
// 00660b66  8d0c28               lea ecx, [eax + ebp]
// 00660b69  2bf1                 sub esi, ecx
// 00660b6b  03f0                 add esi, eax
// 00660b6d  c1fe02               sar esi, 2
// 00660b70  8d04b500000000       lea eax, [esi*4]
// 00660b77  8d3c10               lea edi, [eax + edx]
// 00660b7a  85f6                 test esi, esi
// 00660b7c  760d                 jbe 0x660b8b
// 00660b7e  50                   push eax
// 00660b7f  51                   push ecx
// 00660b80  50                   push eax
// 00660b81  52                   push edx
// 00660b82  ff1580a89e00         call dword ptr [0x9ea880]
// 00660b88  83c410               add esp, 0x10
// 00660b8b  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00660b8f  85c9                 test ecx, ecx
// 00660b91  7604                 jbe 0x660b97
// 00660b93  33c0                 xor eax, eax
// 00660b95  f3ab                 rep stosd dword ptr es:[edi], eax
// 00660b97  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00660b9a  5f                   pop edi
// 00660b9b  5e                   pop esi
// 00660b9c  5d                   pop ebp
// 00660b9d  85c0                 test eax, eax
// 00660b9f  7409                 je 0x660baa
// 00660ba1  50                   push eax
// 00660ba2  e8f36d1400           call 0x7a799a
// 00660ba7  83c404               add esp, 4
// 00660baa  8b442404             mov eax, dword ptr [esp + 4]
// 00660bae  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00660bb2  014b14               add dword ptr [ebx + 0x14], ecx
// 00660bb5  894310               mov dword ptr [ebx + 0x10], eax
// 00660bb8  5b                   pop ebx
// 00660bb9  59                   pop ecx
// 00660bba  c20400               ret 4
// standard library deque<double> (function ?_Growmap@?$deque@NV?$allocator@N@std@@@std@@IAEXI@Z)

// stl: deque<double>
typedef double E;
#include <deque>
template class std::deque<E>;
