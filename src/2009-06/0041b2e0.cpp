// from server: 100% by auto
// roc 2009-06 0041b2e0  unit: CInstanceRecord  size: 352 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041b2e0
//
// 0041b2e0  8b542404             mov edx, dword ptr [esp + 4]
// 0041b2e4  83ec08               sub esp, 8
// 0041b2e7  53                   push ebx
// 0041b2e8  8bd9                 mov ebx, ecx
// 0041b2ea  8b4314               mov eax, dword ptr [ebx + 0x14]
// 0041b2ed  b955555515           mov ecx, 0x15555555
// 0041b2f2  2bc8                 sub ecx, eax
// 0041b2f4  3bca                 cmp ecx, edx
// 0041b2f6  7305                 jae 0x41b2fd
// 0041b2f8  e873450100           call 0x42f870
// 0041b2fd  8bc8                 mov ecx, eax
// 0041b2ff  d1e9                 shr ecx, 1
// 0041b301  83f908               cmp ecx, 8
// 0041b304  7305                 jae 0x41b30b
// 0041b306  b908000000           mov ecx, 8
// 0041b30b  55                   push ebp
// 0041b30c  56                   push esi
// 0041b30d  57                   push edi
// 0041b30e  3bd1                 cmp edx, ecx
// 0041b310  7311                 jae 0x41b323
// 0041b312  be55555515           mov esi, 0x15555555
// 0041b317  2bf1                 sub esi, ecx
// 0041b319  3bc6                 cmp eax, esi
// 0041b31b  7706                 ja 0x41b323
// 0041b31d  8bd1                 mov edx, ecx
// 0041b31f  8954241c             mov dword ptr [esp + 0x1c], edx
// 0041b323  8b7318               mov esi, dword ptr [ebx + 0x18]
// 0041b326  03c2                 add eax, edx
// 0041b328  6a00                 push 0
// 0041b32a  50                   push eax
// 0041b32b  89742418             mov dword ptr [esp + 0x18], esi
// 0041b32f  e8ccd61d00           call 0x5f8a00
// 0041b334  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 0041b337  8944241c             mov dword ptr [esp + 0x1c], eax
// 0041b33b  03f6                 add esi, esi
// 0041b33d  03f6                 add esi, esi
// 0041b33f  8d3c06               lea edi, [esi + eax]
// 0041b342  8b4314               mov eax, dword ptr [ebx + 0x14]
// 0041b345  03c0                 add eax, eax
// 0041b347  03c0                 add eax, eax
// 0041b349  8d140e               lea edx, [esi + ecx]
// 0041b34c  2bc2                 sub eax, edx
// 0041b34e  03c1                 add eax, ecx
// 0041b350  c1f802               sar eax, 2
// 0041b353  83c408               add esp, 8
// 0041b356  8d0c8500000000       lea ecx, [eax*4]
// 0041b35d  8d2c39               lea ebp, [ecx + edi]
// 0041b360  85c0                 test eax, eax
// 0041b362  760d                 jbe 0x41b371
// 0041b364  51                   push ecx
// 0041b365  52                   push edx
// 0041b366  51                   push ecx
// 0041b367  57                   push edi
// 0041b368  ff155ce98900         call dword ptr [0x89e95c]
// 0041b36e  83c410               add esp, 0x10
// 0041b371  8b542410             mov edx, dword ptr [esp + 0x10]
// 0041b375  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0041b379  3bd0                 cmp edx, eax
// 0041b37b  7743                 ja 0x41b3c0
// 0041b37d  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0041b380  c1fe02               sar esi, 2
// 0041b383  8d0cb500000000       lea ecx, [esi*4]
// 0041b38a  8d3c29               lea edi, [ecx + ebp]
// 0041b38d  85f6                 test esi, esi
// 0041b38f  7611                 jbe 0x41b3a2
// 0041b391  51                   push ecx
// 0041b392  50                   push eax
// 0041b393  51                   push ecx
// 0041b394  55                   push ebp
// 0041b395  ff155ce98900         call dword ptr [0x89e95c]
// 0041b39b  8b542420             mov edx, dword ptr [esp + 0x20]
// 0041b39f  83c410               add esp, 0x10
// 0041b3a2  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0041b3a6  2bca                 sub ecx, edx
// 0041b3a8  7408                 je 0x41b3b2
// 0041b3aa  8b542410             mov edx, dword ptr [esp + 0x10]
// 0041b3ae  33c0                 xor eax, eax
// 0041b3b0  f3ab                 rep stosd dword ptr es:[edi], eax
// 0041b3b2  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0041b3b6  85d2                 test edx, edx
// 0041b3b8  7662                 jbe 0x41b41c
// 0041b3ba  8bca                 mov ecx, edx
// 0041b3bc  8bfd                 mov edi, ebp
// 0041b3be  eb58                 jmp 0x41b418
// 0041b3c0  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 0041b3c3  8d3c8500000000       lea edi, [eax*4]
// 0041b3ca  8bc7                 mov eax, edi
// 0041b3cc  c1f802               sar eax, 2
// 0041b3cf  85c0                 test eax, eax
// 0041b3d1  7611                 jbe 0x41b3e4
// 0041b3d3  03c0                 add eax, eax
// 0041b3d5  03c0                 add eax, eax
// 0041b3d7  50                   push eax
// 0041b3d8  51                   push ecx
// 0041b3d9  50                   push eax
// 0041b3da  55                   push ebp
// 0041b3db  ff155ce98900         call dword ptr [0x89e95c]
// 0041b3e1  83c410               add esp, 0x10
// 0041b3e4  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0041b3e7  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0041b3eb  8d0c07               lea ecx, [edi + eax]
// 0041b3ee  2bf1                 sub esi, ecx
// 0041b3f0  03f0                 add esi, eax
// 0041b3f2  c1fe02               sar esi, 2
// 0041b3f5  8d04b500000000       lea eax, [esi*4]
// 0041b3fc  8d3c28               lea edi, [eax + ebp]
// 0041b3ff  85f6                 test esi, esi
// 0041b401  760d                 jbe 0x41b410
// 0041b403  50                   push eax
// 0041b404  51                   push ecx
// 0041b405  50                   push eax
// 0041b406  55                   push ebp
// 0041b407  ff155ce98900         call dword ptr [0x89e95c]
// 0041b40d  83c410               add esp, 0x10
// 0041b410  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0041b414  85c9                 test ecx, ecx
// 0041b416  7604                 jbe 0x41b41c
// 0041b418  33c0                 xor eax, eax
// 0041b41a  f3ab                 rep stosd dword ptr es:[edi], eax
// 0041b41c  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0041b41f  85c0                 test eax, eax
// 0041b421  7409                 je 0x41b42c
// 0041b423  50                   push eax
// 0041b424  e809d62f00           call 0x718a32
// 0041b429  83c404               add esp, 4
// 0041b42c  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0041b430  015314               add dword ptr [ebx + 0x14], edx
// 0041b433  5f                   pop edi
// 0041b434  5e                   pop esi
// 0041b435  896b10               mov dword ptr [ebx + 0x10], ebp
// 0041b438  5d                   pop ebp
// 0041b439  5b                   pop ebx
// 0041b43a  83c408               add esp, 8
// 0041b43d  c20400               ret 4
// standard library deque<pod12> (function ?_Growmap@?$deque@UE@@V?$allocator@UE@@@std@@@std@@IAEXI@Z)

// stl: deque<pod12>
struct E { int v[3]; };
#include <deque>
template class std::deque<E>;
