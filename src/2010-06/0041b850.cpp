// from server: 100% by auto
// roc 2010-06 0041b850  unit: CInstanceRecord  size: 352 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0041b850
//
// 0041b850  8b542404             mov edx, dword ptr [esp + 4]
// 0041b854  83ec08               sub esp, 8
// 0041b857  53                   push ebx
// 0041b858  8bd9                 mov ebx, ecx
// 0041b85a  8b4314               mov eax, dword ptr [ebx + 0x14]
// 0041b85d  b955555515           mov ecx, 0x15555555
// 0041b862  2bc8                 sub ecx, eax
// 0041b864  3bca                 cmp ecx, edx
// 0041b866  7305                 jae 0x41b86d
// 0041b868  e863450a00           call 0x4bfdd0
// 0041b86d  8bc8                 mov ecx, eax
// 0041b86f  d1e9                 shr ecx, 1
// 0041b871  83f908               cmp ecx, 8
// 0041b874  7305                 jae 0x41b87b
// 0041b876  b908000000           mov ecx, 8
// 0041b87b  55                   push ebp
// 0041b87c  56                   push esi
// 0041b87d  57                   push edi
// 0041b87e  3bd1                 cmp edx, ecx
// 0041b880  7311                 jae 0x41b893
// 0041b882  be55555515           mov esi, 0x15555555
// 0041b887  2bf1                 sub esi, ecx
// 0041b889  3bc6                 cmp eax, esi
// 0041b88b  7706                 ja 0x41b893
// 0041b88d  8bd1                 mov edx, ecx
// 0041b88f  8954241c             mov dword ptr [esp + 0x1c], edx
// 0041b893  8b7318               mov esi, dword ptr [ebx + 0x18]
// 0041b896  03c2                 add eax, edx
// 0041b898  6a00                 push 0
// 0041b89a  50                   push eax
// 0041b89b  89742418             mov dword ptr [esp + 0x18], esi
// 0041b89f  e86c9a4b00           call 0x8d5310
// 0041b8a4  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 0041b8a7  8944241c             mov dword ptr [esp + 0x1c], eax
// 0041b8ab  03f6                 add esi, esi
// 0041b8ad  03f6                 add esi, esi
// 0041b8af  8d3c06               lea edi, [esi + eax]
// 0041b8b2  8b4314               mov eax, dword ptr [ebx + 0x14]
// 0041b8b5  03c0                 add eax, eax
// 0041b8b7  03c0                 add eax, eax
// 0041b8b9  8d140e               lea edx, [esi + ecx]
// 0041b8bc  2bc2                 sub eax, edx
// 0041b8be  03c1                 add eax, ecx
// 0041b8c0  c1f802               sar eax, 2
// 0041b8c3  83c408               add esp, 8
// 0041b8c6  8d0c8500000000       lea ecx, [eax*4]
// 0041b8cd  8d2c39               lea ebp, [ecx + edi]
// 0041b8d0  85c0                 test eax, eax
// 0041b8d2  760d                 jbe 0x41b8e1
// 0041b8d4  51                   push ecx
// 0041b8d5  52                   push edx
// 0041b8d6  51                   push ecx
// 0041b8d7  57                   push edi
// 0041b8d8  ff1580a89e00         call dword ptr [0x9ea880]
// 0041b8de  83c410               add esp, 0x10
// 0041b8e1  8b542410             mov edx, dword ptr [esp + 0x10]
// 0041b8e5  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0041b8e9  3bd0                 cmp edx, eax
// 0041b8eb  7743                 ja 0x41b930
// 0041b8ed  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0041b8f0  c1fe02               sar esi, 2
// 0041b8f3  8d0cb500000000       lea ecx, [esi*4]
// 0041b8fa  8d3c29               lea edi, [ecx + ebp]
// 0041b8fd  85f6                 test esi, esi
// 0041b8ff  7611                 jbe 0x41b912
// 0041b901  51                   push ecx
// 0041b902  50                   push eax
// 0041b903  51                   push ecx
// 0041b904  55                   push ebp
// 0041b905  ff1580a89e00         call dword ptr [0x9ea880]
// 0041b90b  8b542420             mov edx, dword ptr [esp + 0x20]
// 0041b90f  83c410               add esp, 0x10
// 0041b912  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0041b916  2bca                 sub ecx, edx
// 0041b918  7408                 je 0x41b922
// 0041b91a  8b542410             mov edx, dword ptr [esp + 0x10]
// 0041b91e  33c0                 xor eax, eax
// 0041b920  f3ab                 rep stosd dword ptr es:[edi], eax
// 0041b922  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0041b926  85d2                 test edx, edx
// 0041b928  7662                 jbe 0x41b98c
// 0041b92a  8bca                 mov ecx, edx
// 0041b92c  8bfd                 mov edi, ebp
// 0041b92e  eb58                 jmp 0x41b988
// 0041b930  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 0041b933  8d3c8500000000       lea edi, [eax*4]
// 0041b93a  8bc7                 mov eax, edi
// 0041b93c  c1f802               sar eax, 2
// 0041b93f  85c0                 test eax, eax
// 0041b941  7611                 jbe 0x41b954
// 0041b943  03c0                 add eax, eax
// 0041b945  03c0                 add eax, eax
// 0041b947  50                   push eax
// 0041b948  51                   push ecx
// 0041b949  50                   push eax
// 0041b94a  55                   push ebp
// 0041b94b  ff1580a89e00         call dword ptr [0x9ea880]
// 0041b951  83c410               add esp, 0x10
// 0041b954  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0041b957  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0041b95b  8d0c07               lea ecx, [edi + eax]
// 0041b95e  2bf1                 sub esi, ecx
// 0041b960  03f0                 add esi, eax
// 0041b962  c1fe02               sar esi, 2
// 0041b965  8d04b500000000       lea eax, [esi*4]
// 0041b96c  8d3c28               lea edi, [eax + ebp]
// 0041b96f  85f6                 test esi, esi
// 0041b971  760d                 jbe 0x41b980
// 0041b973  50                   push eax
// 0041b974  51                   push ecx
// 0041b975  50                   push eax
// 0041b976  55                   push ebp
// 0041b977  ff1580a89e00         call dword ptr [0x9ea880]
// 0041b97d  83c410               add esp, 0x10
// 0041b980  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0041b984  85c9                 test ecx, ecx
// 0041b986  7604                 jbe 0x41b98c
// 0041b988  33c0                 xor eax, eax
// 0041b98a  f3ab                 rep stosd dword ptr es:[edi], eax
// 0041b98c  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0041b98f  85c0                 test eax, eax
// 0041b991  7409                 je 0x41b99c
// 0041b993  50                   push eax
// 0041b994  e801c03800           call 0x7a799a
// 0041b999  83c404               add esp, 4
// 0041b99c  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0041b9a0  015314               add dword ptr [ebx + 0x14], edx
// 0041b9a3  5f                   pop edi
// 0041b9a4  5e                   pop esi
// 0041b9a5  896b10               mov dword ptr [ebx + 0x10], ebp
// 0041b9a8  5d                   pop ebp
// 0041b9a9  5b                   pop ebx
// 0041b9aa  83c408               add esp, 8
// 0041b9ad  c20400               ret 4
// standard library deque<pod12> (function ?_Growmap@?$deque@UE@@V?$allocator@UE@@@std@@@std@@IAEXI@Z)

// stl: deque<pod12>
struct E { int v[3]; };
#include <deque>
template class std::deque<E>;
