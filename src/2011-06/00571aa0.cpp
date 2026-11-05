// from server: 100% by auto
// roc 2011-06 00571aa0  unit: seg_00570000  size: 436 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00571aa0
//
// 00571aa0  53                   push ebx
// 00571aa1  55                   push ebp
// 00571aa2  56                   push esi
// 00571aa3  8b742410             mov esi, dword ptr [esp + 0x10]
// 00571aa7  f6466801             test byte ptr [esi + 0x68], 1
// 00571aab  57                   push edi
// 00571aac  750e                 jne 0x571abc
// 00571aae  682c70a800           push 0xa8702c
// 00571ab3  56                   push esi
// 00571ab4  e877f8feff           call 0x561330
// 00571ab9  83c408               add esp, 8
// 00571abc  8b4668               mov eax, dword ptr [esi + 0x68]
// 00571abf  a804                 test al, 4
// 00571ac1  7406                 je 0x571ac9
// 00571ac3  83c808               or eax, 8
// 00571ac6  894668               mov dword ptr [esi + 0x68], eax
// 00571ac9  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 00571acf  50                   push eax
// 00571ad0  56                   push esi
// 00571ad1  e8cafbfeff           call 0x5616a0
// 00571ad6  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 00571ada  8d4d01               lea ecx, [ebp + 1]
// 00571add  51                   push ecx
// 00571ade  56                   push esi
// 00571adf  e8ecfbfeff           call 0x5616d0
// 00571ae4  8bf8                 mov edi, eax
// 00571ae6  33db                 xor ebx, ebx
// 00571ae8  83c410               add esp, 0x10
// 00571aeb  89be88020000         mov dword ptr [esi + 0x288], edi
// 00571af1  3bfb                 cmp edi, ebx
// 00571af3  7513                 jne 0x571b08
// 00571af5  680470a800           push 0xa87004
// 00571afa  56                   push esi
// 00571afb  e8e0f8feff           call 0x5613e0
// 00571b00  83c408               add esp, 8
// 00571b03  5f                   pop edi
// 00571b04  5e                   pop esi
// 00571b05  5d                   pop ebp
// 00571b06  5b                   pop ebx
// 00571b07  c3                   ret 
// 00571b08  55                   push ebp
// 00571b09  57                   push edi
// 00571b0a  56                   push esi
// 00571b0b  e860f4feff           call 0x560f70
// 00571b10  55                   push ebp
// 00571b11  57                   push edi
// 00571b12  56                   push esi
// 00571b13  e838edfdff           call 0x550850
// 00571b18  53                   push ebx
// 00571b19  56                   push esi
// 00571b1a  e821ddffff           call 0x56f840
// 00571b1f  83c420               add esp, 0x20
// 00571b22  85c0                 test eax, eax
// 00571b24  741b                 je 0x571b41
// 00571b26  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 00571b2c  52                   push edx
// 00571b2d  56                   push esi
// 00571b2e  e86dfbfeff           call 0x5616a0
// 00571b33  83c408               add esp, 8
// 00571b36  5f                   pop edi
// 00571b37  899e88020000         mov dword ptr [esi + 0x288], ebx
// 00571b3d  5e                   pop esi
// 00571b3e  5d                   pop ebp
// 00571b3f  5b                   pop ebx
// 00571b40  c3                   ret 
// 00571b41  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 00571b47  881c28               mov byte ptr [eax + ebp], bl
// 00571b4a  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 00571b50  8bf8                 mov edi, eax
// 00571b52  381f                 cmp byte ptr [edi], bl
// 00571b54  7405                 je 0x571b5b
// 00571b56  47                   inc edi
// 00571b57  381f                 cmp byte ptr [edi], bl
// 00571b59  75fb                 jne 0x571b56
// 00571b5b  8d4c28fe             lea ecx, [eax + ebp - 2]
// 00571b5f  3bf9                 cmp edi, ecx
// 00571b61  7226                 jb 0x571b89
// 00571b63  68ec6fa800           push 0xa86fec
// 00571b68  56                   push esi
// 00571b69  e872f8feff           call 0x5613e0
// 00571b6e  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 00571b74  52                   push edx
// 00571b75  56                   push esi
// 00571b76  e825fbfeff           call 0x5616a0
// 00571b7b  83c410               add esp, 0x10
// 00571b7e  5f                   pop edi
// 00571b7f  899e88020000         mov dword ptr [esi + 0x288], ebx
// 00571b85  5e                   pop esi
// 00571b86  5d                   pop ebp
// 00571b87  5b                   pop ebx
// 00571b88  c3                   ret 
// 00571b89  0fbe5f01             movsx ebx, byte ptr [edi + 1]
// 00571b8d  47                   inc edi
// 00571b8e  85db                 test ebx, ebx
// 00571b90  7410                 je 0x571ba2
// 00571b92  68c46fa800           push 0xa86fc4
// 00571b97  56                   push esi
// 00571b98  e843f8feff           call 0x5613e0
// 00571b9d  83c408               add esp, 8
// 00571ba0  33db                 xor ebx, ebx
// 00571ba2  2bbe88020000         sub edi, dword ptr [esi + 0x288]
// 00571ba8  8d442414             lea eax, [esp + 0x14]
// 00571bac  50                   push eax
// 00571bad  47                   inc edi
// 00571bae  57                   push edi
// 00571baf  55                   push ebp
// 00571bb0  53                   push ebx
// 00571bb1  56                   push esi
// 00571bb2  e8c9cbffff           call 0x56e780
// 00571bb7  6a10                 push 0x10
// 00571bb9  56                   push esi
// 00571bba  e811fbfeff           call 0x5616d0
// 00571bbf  8be8                 mov ebp, eax
// 00571bc1  83c41c               add esp, 0x1c
// 00571bc4  85ed                 test ebp, ebp
// 00571bc6  7526                 jne 0x571bee
// 00571bc8  68986fa800           push 0xa86f98
// 00571bcd  56                   push esi
// 00571bce  e80df8feff           call 0x5613e0
// 00571bd3  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 00571bd9  51                   push ecx
// 00571bda  56                   push esi
// 00571bdb  e8c0fafeff           call 0x5616a0
// 00571be0  83c410               add esp, 0x10
// 00571be3  5f                   pop edi
// 00571be4  89ae88020000         mov dword ptr [esi + 0x288], ebp
// 00571bea  5e                   pop esi
// 00571beb  5d                   pop ebp
// 00571bec  5b                   pop ebx
// 00571bed  c3                   ret 
// 00571bee  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00571bf2  895d00               mov dword ptr [ebp], ebx
// 00571bf5  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 00571bfb  6a01                 push 1
// 00571bfd  895504               mov dword ptr [ebp + 4], edx
// 00571c00  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 00571c06  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00571c0a  55                   push ebp
// 00571c0b  52                   push edx
// 00571c0c  03c7                 add eax, edi
// 00571c0e  56                   push esi
// 00571c0f  894508               mov dword ptr [ebp + 8], eax
// 00571c12  894d0c               mov dword ptr [ebp + 0xc], ecx
// 00571c15  e85686feff           call 0x55a270
// 00571c1a  55                   push ebp
// 00571c1b  56                   push esi
// 00571c1c  8bf8                 mov edi, eax
// 00571c1e  e87dfafeff           call 0x5616a0
// 00571c23  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 00571c29  50                   push eax
// 00571c2a  56                   push esi
// 00571c2b  e870fafeff           call 0x5616a0
// 00571c30  83c420               add esp, 0x20
// 00571c33  c7868802000000000000 mov dword ptr [esi + 0x288], 0
// 00571c3d  85ff                 test edi, edi
// 00571c3f  740e                 je 0x571c4f
// 00571c41  686c6fa800           push 0xa86f6c
// 00571c46  56                   push esi
// 00571c47  e8e4f6feff           call 0x561330
// 00571c4c  83c408               add esp, 8
// 00571c4f  5f                   pop edi
// 00571c50  5e                   pop esi
// 00571c51  5d                   pop ebp
// 00571c52  5b                   pop ebx
// 00571c53  c3                   ret 
// library libpng-1.2.32/pngrutil.c (function _png_handle_zTXt)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngrutil.c
