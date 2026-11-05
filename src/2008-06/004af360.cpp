// from server: 100% by auto
// roc 2008-06 004af360  unit: RBX::Network::Replicator::MarkerItem  size: 349 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004af360
//
// 004af360  51                   push ecx
// 004af361  8b542408             mov edx, dword ptr [esp + 8]
// 004af365  53                   push ebx
// 004af366  8bd9                 mov ebx, ecx
// 004af368  8b4314               mov eax, dword ptr [ebx + 0x14]
// 004af36b  b9ffffff0f           mov ecx, 0xfffffff
// 004af370  2bc8                 sub ecx, eax
// 004af372  3bca                 cmp ecx, edx
// 004af374  7305                 jae 0x4af37b
// 004af376  e895760600           call 0x516a10
// 004af37b  8bc8                 mov ecx, eax
// 004af37d  d1e9                 shr ecx, 1
// 004af37f  83f908               cmp ecx, 8
// 004af382  7305                 jae 0x4af389
// 004af384  b908000000           mov ecx, 8
// 004af389  55                   push ebp
// 004af38a  56                   push esi
// 004af38b  57                   push edi
// 004af38c  3bd1                 cmp edx, ecx
// 004af38e  7311                 jae 0x4af3a1
// 004af390  beffffff0f           mov esi, 0xfffffff
// 004af395  2bf1                 sub esi, ecx
// 004af397  3bc6                 cmp eax, esi
// 004af399  7706                 ja 0x4af3a1
// 004af39b  894c2418             mov dword ptr [esp + 0x18], ecx
// 004af39f  8bd1                 mov edx, ecx
// 004af3a1  8b6b18               mov ebp, dword ptr [ebx + 0x18]
// 004af3a4  03c2                 add eax, edx
// 004af3a6  6a00                 push 0
// 004af3a8  50                   push eax
// 004af3a9  d1ed                 shr ebp, 1
// 004af3ab  e8a017f7ff           call 0x420b50
// 004af3b0  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 004af3b3  89442418             mov dword ptr [esp + 0x18], eax
// 004af3b7  8d34ad00000000       lea esi, [ebp*4]
// 004af3be  8d3c06               lea edi, [esi + eax]
// 004af3c1  8b4314               mov eax, dword ptr [ebx + 0x14]
// 004af3c4  03c0                 add eax, eax
// 004af3c6  03c0                 add eax, eax
// 004af3c8  8d140e               lea edx, [esi + ecx]
// 004af3cb  2bc2                 sub eax, edx
// 004af3cd  03c1                 add eax, ecx
// 004af3cf  c1f802               sar eax, 2
// 004af3d2  8d0c8500000000       lea ecx, [eax*4]
// 004af3d9  83c408               add esp, 8
// 004af3dc  03f9                 add edi, ecx
// 004af3de  85c0                 test eax, eax
// 004af3e0  7614                 jbe 0x4af3f6
// 004af3e2  51                   push ecx
// 004af3e3  52                   push edx
// 004af3e4  8b542418             mov edx, dword ptr [esp + 0x18]
// 004af3e8  51                   push ecx
// 004af3e9  8d0416               lea eax, [esi + edx]
// 004af3ec  50                   push eax
// 004af3ed  ff1550288000         call dword ptr [0x802850]
// 004af3f3  83c410               add esp, 0x10
// 004af3f6  8b442418             mov eax, dword ptr [esp + 0x18]
// 004af3fa  3be8                 cmp ebp, eax
// 004af3fc  773d                 ja 0x4af43b
// 004af3fe  8b4310               mov eax, dword ptr [ebx + 0x10]
// 004af401  c1fe02               sar esi, 2
// 004af404  8bce                 mov ecx, esi
// 004af406  8d148d00000000       lea edx, [ecx*4]
// 004af40d  8d343a               lea esi, [edx + edi]
// 004af410  85c9                 test ecx, ecx
// 004af412  760d                 jbe 0x4af421
// 004af414  52                   push edx
// 004af415  50                   push eax
// 004af416  52                   push edx
// 004af417  57                   push edi
// 004af418  ff1550288000         call dword ptr [0x802850]
// 004af41e  83c410               add esp, 0x10
// 004af421  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004af425  2bcd                 sub ecx, ebp
// 004af427  7406                 je 0x4af42f
// 004af429  33c0                 xor eax, eax
// 004af42b  8bfe                 mov edi, esi
// 004af42d  f3ab                 rep stosd dword ptr es:[edi], eax
// 004af42f  85ed                 test ebp, ebp
// 004af431  7664                 jbe 0x4af497
// 004af433  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004af437  8bcd                 mov ecx, ebp
// 004af439  eb58                 jmp 0x4af493
// 004af43b  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 004af43e  8d2c8500000000       lea ebp, [eax*4]
// 004af445  8bc5                 mov eax, ebp
// 004af447  c1f802               sar eax, 2
// 004af44a  85c0                 test eax, eax
// 004af44c  7611                 jbe 0x4af45f
// 004af44e  03c0                 add eax, eax
// 004af450  03c0                 add eax, eax
// 004af452  50                   push eax
// 004af453  51                   push ecx
// 004af454  50                   push eax
// 004af455  57                   push edi
// 004af456  ff1550288000         call dword ptr [0x802850]
// 004af45c  83c410               add esp, 0x10
// 004af45f  8b4310               mov eax, dword ptr [ebx + 0x10]
// 004af462  8b542410             mov edx, dword ptr [esp + 0x10]
// 004af466  8d0c28               lea ecx, [eax + ebp]
// 004af469  2bf1                 sub esi, ecx
// 004af46b  03f0                 add esi, eax
// 004af46d  c1fe02               sar esi, 2
// 004af470  8d04b500000000       lea eax, [esi*4]
// 004af477  8d3c10               lea edi, [eax + edx]
// 004af47a  85f6                 test esi, esi
// 004af47c  760d                 jbe 0x4af48b
// 004af47e  50                   push eax
// 004af47f  51                   push ecx
// 004af480  50                   push eax
// 004af481  52                   push edx
// 004af482  ff1550288000         call dword ptr [0x802850]
// 004af488  83c410               add esp, 0x10
// 004af48b  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004af48f  85c9                 test ecx, ecx
// 004af491  7604                 jbe 0x4af497
// 004af493  33c0                 xor eax, eax
// 004af495  f3ab                 rep stosd dword ptr es:[edi], eax
// 004af497  8b4310               mov eax, dword ptr [ebx + 0x10]
// 004af49a  5f                   pop edi
// 004af49b  5e                   pop esi
// 004af49c  5d                   pop ebp
// 004af49d  85c0                 test eax, eax
// 004af49f  7409                 je 0x4af4aa
// 004af4a1  50                   push eax
// 004af4a2  e8d3111f00           call 0x6a067a
// 004af4a7  83c404               add esp, 4
// 004af4aa  8b442404             mov eax, dword ptr [esp + 4]
// 004af4ae  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004af4b2  014b14               add dword ptr [ebx + 0x14], ecx
// 004af4b5  894310               mov dword ptr [ebx + 0x10], eax
// 004af4b8  5b                   pop ebx
// 004af4b9  59                   pop ecx
// 004af4ba  c20400               ret 4
// standard library deque<double> (function ?_Growmap@?$deque@NV?$allocator@N@std@@@std@@IAEXI@Z)

// stl: deque<double>
typedef double E;
#include <deque>
template class std::deque<E>;
