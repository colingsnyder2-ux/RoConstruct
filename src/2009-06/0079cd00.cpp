// from server: 100% by auto
// roc 2009-06 0079cd00  unit: CXTPControlGalleryPaintManager  size: 361 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0079cd00
//
// 0079cd00  53                   push ebx
// 0079cd01  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0079cd05  56                   push esi
// 0079cd06  57                   push edi
// 0079cd07  33ff                 xor edi, edi
// 0079cd09  3bdf                 cmp ebx, edi
// 0079cd0b  8bf1                 mov esi, ecx
// 0079cd0d  7d05                 jge 0x79cd14
// 0079cd0f  e8d0bff7ff           call 0x718ce4
// 0079cd14  8b442414             mov eax, dword ptr [esp + 0x14]
// 0079cd18  3bc7                 cmp eax, edi
// 0079cd1a  7c03                 jl 0x79cd1f
// 0079cd1c  894610               mov dword ptr [esi + 0x10], eax
// 0079cd1f  3bdf                 cmp ebx, edi
// 0079cd21  751f                 jne 0x79cd42
// 0079cd23  8b4604               mov eax, dword ptr [esi + 4]
// 0079cd26  3bc7                 cmp eax, edi
// 0079cd28  740c                 je 0x79cd36
// 0079cd2a  50                   push eax
// 0079cd2b  e8aebff7ff           call 0x718cde
// 0079cd30  83c404               add esp, 4
// 0079cd33  897e04               mov dword ptr [esi + 4], edi
// 0079cd36  897e0c               mov dword ptr [esi + 0xc], edi
// 0079cd39  897e08               mov dword ptr [esi + 8], edi
// 0079cd3c  5f                   pop edi
// 0079cd3d  5e                   pop esi
// 0079cd3e  5b                   pop ebx
// 0079cd3f  c20800               ret 8
// 0079cd42  8b5604               mov edx, dword ptr [esi + 4]
// 0079cd45  55                   push ebp
// 0079cd46  3bd7                 cmp edx, edi
// 0079cd48  7535                 jne 0x79cd7f
// 0079cd4a  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 0079cd4d  3bdd                 cmp ebx, ebp
// 0079cd4f  7e02                 jle 0x79cd53
// 0079cd51  8beb                 mov ebp, ebx
// 0079cd53  8d7c6d00             lea edi, [ebp + ebp*2]
// 0079cd57  03ff                 add edi, edi
// 0079cd59  03ff                 add edi, edi
// 0079cd5b  03ff                 add edi, edi
// 0079cd5d  57                   push edi
// 0079cd5e  e8b7bff7ff           call 0x718d1a
// 0079cd63  57                   push edi
// 0079cd64  6a00                 push 0
// 0079cd66  50                   push eax
// 0079cd67  894604               mov dword ptr [esi + 4], eax
// 0079cd6a  e805cff7ff           call 0x719c74
// 0079cd6f  83c410               add esp, 0x10
// 0079cd72  896e0c               mov dword ptr [esi + 0xc], ebp
// 0079cd75  5d                   pop ebp
// 0079cd76  5f                   pop edi
// 0079cd77  895e08               mov dword ptr [esi + 8], ebx
// 0079cd7a  5e                   pop esi
// 0079cd7b  5b                   pop ebx
// 0079cd7c  c20800               ret 8
// 0079cd7f  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0079cd82  3bd9                 cmp ebx, ecx
// 0079cd84  7f33                 jg 0x79cdb9
// 0079cd86  8b4e08               mov ecx, dword ptr [esi + 8]
// 0079cd89  3bd9                 cmp ebx, ecx
// 0079cd8b  0f8ece000000         jle 0x79ce5f
// 0079cd91  8bc3                 mov eax, ebx
// 0079cd93  2bc1                 sub eax, ecx
// 0079cd95  8d0440               lea eax, [eax + eax*2]
// 0079cd98  03c0                 add eax, eax
// 0079cd9a  03c0                 add eax, eax
// 0079cd9c  03c0                 add eax, eax
// 0079cd9e  50                   push eax
// 0079cd9f  8d0c49               lea ecx, [ecx + ecx*2]
// 0079cda2  8d14ca               lea edx, [edx + ecx*8]
// 0079cda5  57                   push edi
// 0079cda6  52                   push edx
// 0079cda7  e8c8cef7ff           call 0x719c74
// 0079cdac  83c40c               add esp, 0xc
// 0079cdaf  5d                   pop ebp
// 0079cdb0  5f                   pop edi
// 0079cdb1  895e08               mov dword ptr [esi + 8], ebx
// 0079cdb4  5e                   pop esi
// 0079cdb5  5b                   pop ebx
// 0079cdb6  c20800               ret 8
// 0079cdb9  8b4610               mov eax, dword ptr [esi + 0x10]
// 0079cdbc  3bc7                 cmp eax, edi
// 0079cdbe  7524                 jne 0x79cde4
// 0079cdc0  8b4608               mov eax, dword ptr [esi + 8]
// 0079cdc3  99                   cdq 
// 0079cdc4  83e207               and edx, 7
// 0079cdc7  03c2                 add eax, edx
// 0079cdc9  c1f803               sar eax, 3
// 0079cdcc  83f804               cmp eax, 4
// 0079cdcf  7d07                 jge 0x79cdd8
// 0079cdd1  b804000000           mov eax, 4
// 0079cdd6  eb0c                 jmp 0x79cde4
// 0079cdd8  3d00040000           cmp eax, 0x400
// 0079cddd  7e05                 jle 0x79cde4
// 0079cddf  b800040000           mov eax, 0x400
// 0079cde4  8d3c01               lea edi, [ecx + eax]
// 0079cde7  3bdf                 cmp ebx, edi
// 0079cde9  7d06                 jge 0x79cdf1
// 0079cdeb  897c2414             mov dword ptr [esp + 0x14], edi
// 0079cdef  eb06                 jmp 0x79cdf7
// 0079cdf1  895c2414             mov dword ptr [esp + 0x14], ebx
// 0079cdf5  8bfb                 mov edi, ebx
// 0079cdf7  3bf9                 cmp edi, ecx
// 0079cdf9  7d05                 jge 0x79ce00
// 0079cdfb  e8e4bef7ff           call 0x718ce4
// 0079ce00  8d3c7f               lea edi, [edi + edi*2]
// 0079ce03  03ff                 add edi, edi
// 0079ce05  03ff                 add edi, edi
// 0079ce07  03ff                 add edi, edi
// 0079ce09  57                   push edi
// 0079ce0a  e80bbff7ff           call 0x718d1a
// 0079ce0f  8b4e04               mov ecx, dword ptr [esi + 4]
// 0079ce12  8be8                 mov ebp, eax
// 0079ce14  8b4608               mov eax, dword ptr [esi + 8]
// 0079ce17  8d0440               lea eax, [eax + eax*2]
// 0079ce1a  03c0                 add eax, eax
// 0079ce1c  03c0                 add eax, eax
// 0079ce1e  03c0                 add eax, eax
// 0079ce20  50                   push eax
// 0079ce21  51                   push ecx
// 0079ce22  57                   push edi
// 0079ce23  55                   push ebp
// 0079ce24  e8a760c6ff           call 0x402ed0
// 0079ce29  8b4e08               mov ecx, dword ptr [esi + 8]
// 0079ce2c  8bc3                 mov eax, ebx
// 0079ce2e  2bc1                 sub eax, ecx
// 0079ce30  8d1440               lea edx, [eax + eax*2]
// 0079ce33  03d2                 add edx, edx
// 0079ce35  03d2                 add edx, edx
// 0079ce37  03d2                 add edx, edx
// 0079ce39  52                   push edx
// 0079ce3a  8d0449               lea eax, [ecx + ecx*2]
// 0079ce3d  8d4cc500             lea ecx, [ebp + eax*8]
// 0079ce41  6a00                 push 0
// 0079ce43  51                   push ecx
// 0079ce44  e82bcef7ff           call 0x719c74
// 0079ce49  8b5604               mov edx, dword ptr [esi + 4]
// 0079ce4c  52                   push edx
// 0079ce4d  e88cbef7ff           call 0x718cde
// 0079ce52  8b442438             mov eax, dword ptr [esp + 0x38]
// 0079ce56  83c424               add esp, 0x24
// 0079ce59  896e04               mov dword ptr [esi + 4], ebp
// 0079ce5c  89460c               mov dword ptr [esi + 0xc], eax
// 0079ce5f  5d                   pop ebp
// 0079ce60  5f                   pop edi
// 0079ce61  895e08               mov dword ptr [esi + 8], ebx
// 0079ce64  5e                   pop esi
// 0079ce65  5b                   pop ebx
// 0079ce66  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPControlGallery.cpp (function ?SetSize@?$CArray@UGALLERYITEM_POSITION@CXTPControlGallery@@AAU12@@@QAEXHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlGallery.cpp
