// from server: 100% by auto
// roc 2010-06 008a8980  unit: CXTCaptionButtonTheme  size: 367 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a8980
//
// 008a8980  83ec20               sub esp, 0x20
// 008a8983  53                   push ebx
// 008a8984  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 008a8988  8b03                 mov eax, dword ptr [ebx]
// 008a898a  8b5308               mov edx, dword ptr [ebx + 8]
// 008a898d  55                   push ebp
// 008a898e  56                   push esi
// 008a898f  57                   push edi
// 008a8990  8be9                 mov ebp, ecx
// 008a8992  8b4b04               mov ecx, dword ptr [ebx + 4]
// 008a8995  6a00                 push 0
// 008a8997  894c2428             mov dword ptr [esp + 0x28], ecx
// 008a899b  89442424             mov dword ptr [esp + 0x24], eax
// 008a899f  8b430c               mov eax, dword ptr [ebx + 0xc]
// 008a89a2  6afe                 push -2
// 008a89a4  8d4c2428             lea ecx, [esp + 0x28]
// 008a89a8  51                   push ecx
// 008a89a9  89542434             mov dword ptr [esp + 0x34], edx
// 008a89ad  89442438             mov dword ptr [esp + 0x38], eax
// 008a89b1  ff15dcbb9e00         call dword ptr [0x9ebbdc]
// 008a89b7  8b742434             mov esi, dword ptr [esp + 0x34]
// 008a89bb  8b542420             mov edx, dword ptr [esp + 0x20]
// 008a89bf  8b442424             mov eax, dword ptr [esp + 0x24]
// 008a89c3  8b7c2444             mov edi, dword ptr [esp + 0x44]
// 008a89c7  8916                 mov dword ptr [esi], edx
// 008a89c9  894604               mov dword ptr [esi + 4], eax
// 008a89cc  837f7800             cmp dword ptr [edi + 0x78], 0
// 008a89d0  7422                 je 0x8a89f4
// 008a89d2  8d4c2410             lea ecx, [esp + 0x10]
// 008a89d6  51                   push ecx
// 008a89d7  8bcf                 mov ecx, edi
// 008a89d9  e8a217ffff           call 0x89a180
// 008a89de  8b10                 mov edx, dword ptr [eax]
// 008a89e0  8916                 mov dword ptr [esi], edx
// 008a89e2  8b4004               mov eax, dword ptr [eax + 4]
// 008a89e5  5f                   pop edi
// 008a89e6  894604               mov dword ptr [esi + 4], eax
// 008a89e9  8bc6                 mov eax, esi
// 008a89eb  5e                   pop esi
// 008a89ec  5d                   pop ebp
// 008a89ed  5b                   pop ebx
// 008a89ee  83c420               add esp, 0x20
// 008a89f1  c21400               ret 0x14
// 008a89f4  8b442440             mov eax, dword ptr [esp + 0x40]
// 008a89f8  8b4804               mov ecx, dword ptr [eax + 4]
// 008a89fb  8b00                 mov eax, dword ptr [eax]
// 008a89fd  8b5500               mov edx, dword ptr [ebp]
// 008a8a00  8b5240               mov edx, dword ptr [edx + 0x40]
// 008a8a03  57                   push edi
// 008a8a04  51                   push ecx
// 008a8a05  50                   push eax
// 008a8a06  56                   push esi
// 008a8a07  8bcd                 mov ecx, ebp
// 008a8a09  ffd2                 call edx
// 008a8a0b  8b476c               mov eax, dword ptr [edi + 0x6c]
// 008a8a0e  8906                 mov dword ptr [esi], eax
// 008a8a10  8b17                 mov edx, dword ptr [edi]
// 008a8a12  8b8268010000         mov eax, dword ptr [edx + 0x168]
// 008a8a18  8bcf                 mov ecx, edi
// 008a8a1a  ffd0                 call eax
// 008a8a1c  a804                 test al, 4
// 008a8a1e  7425                 je 0x8a8a45
// 008a8a20  8b6f70               mov ebp, dword ptr [edi + 0x70]
// 008a8a23  8d4c2410             lea ecx, [esp + 0x10]
// 008a8a27  51                   push ecx
// 008a8a28  8bcf                 mov ecx, edi
// 008a8a2a  e8d116ffff           call 0x89a100
// 008a8a2f  8b4004               mov eax, dword ptr [eax + 4]
// 008a8a32  99                   cdq 
// 008a8a33  2bc2                 sub eax, edx
// 008a8a35  8bc8                 mov ecx, eax
// 008a8a37  8bc5                 mov eax, ebp
// 008a8a39  99                   cdq 
// 008a8a3a  2bc2                 sub eax, edx
// 008a8a3c  d1f9                 sar ecx, 1
// 008a8a3e  d1f8                 sar eax, 1
// 008a8a40  03c8                 add ecx, eax
// 008a8a42  014e04               add dword ptr [esi + 4], ecx
// 008a8a45  8bcf                 mov ecx, edi
// 008a8a47  e892430d00           call 0x97cdde
// 008a8a4c  2500030000           and eax, 0x300
// 008a8a51  3d00010000           cmp eax, 0x100
// 008a8a56  7466                 je 0x8a8abe
// 008a8a58  3d00020000           cmp eax, 0x200
// 008a8a5d  7445                 je 0x8a8aa4
// 008a8a5f  8b17                 mov edx, dword ptr [edi]
// 008a8a61  8b8268010000         mov eax, dword ptr [edx + 0x168]
// 008a8a67  8bcf                 mov ecx, edi
// 008a8a69  ffd0                 call eax
// 008a8a6b  a804                 test al, 4
// 008a8a6d  7510                 jne 0x8a8a7f
// 008a8a6f  8d4c2410             lea ecx, [esp + 0x10]
// 008a8a73  51                   push ecx
// 008a8a74  8bcf                 mov ecx, edi
// 008a8a76  e88516ffff           call 0x89a100
// 008a8a7b  8b10                 mov edx, dword ptr [eax]
// 008a8a7d  0116                 add dword ptr [esi], edx
// 008a8a7f  8b4308               mov eax, dword ptr [ebx + 8]
// 008a8a82  2b476c               sub eax, dword ptr [edi + 0x6c]
// 008a8a85  8b542440             mov edx, dword ptr [esp + 0x40]
// 008a8a89  2b02                 sub eax, dword ptr [edx]
// 008a8a8b  8b0e                 mov ecx, dword ptr [esi]
// 008a8a8d  2bc1                 sub eax, ecx
// 008a8a8f  99                   cdq 
// 008a8a90  2bc2                 sub eax, edx
// 008a8a92  d1f8                 sar eax, 1
// 008a8a94  03c1                 add eax, ecx
// 008a8a96  5f                   pop edi
// 008a8a97  8906                 mov dword ptr [esi], eax
// 008a8a99  8bc6                 mov eax, esi
// 008a8a9b  5e                   pop esi
// 008a8a9c  5d                   pop ebp
// 008a8a9d  5b                   pop ebx
// 008a8a9e  83c420               add esp, 0x20
// 008a8aa1  c21400               ret 0x14
// 008a8aa4  8b4308               mov eax, dword ptr [ebx + 8]
// 008a8aa7  2b476c               sub eax, dword ptr [edi + 0x6c]
// 008a8aaa  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 008a8aae  2b01                 sub eax, dword ptr [ecx]
// 008a8ab0  5f                   pop edi
// 008a8ab1  8906                 mov dword ptr [esi], eax
// 008a8ab3  8bc6                 mov eax, esi
// 008a8ab5  5e                   pop esi
// 008a8ab6  5d                   pop ebp
// 008a8ab7  5b                   pop ebx
// 008a8ab8  83c420               add esp, 0x20
// 008a8abb  c21400               ret 0x14
// 008a8abe  8b17                 mov edx, dword ptr [edi]
// 008a8ac0  8b8268010000         mov eax, dword ptr [edx + 0x168]
// 008a8ac6  8bcf                 mov ecx, edi
// 008a8ac8  ffd0                 call eax
// 008a8aca  a804                 test al, 4
// 008a8acc  7515                 jne 0x8a8ae3
// 008a8ace  8b5f70               mov ebx, dword ptr [edi + 0x70]
// 008a8ad1  8d4c2418             lea ecx, [esp + 0x18]
// 008a8ad5  51                   push ecx
// 008a8ad6  8bcf                 mov ecx, edi
// 008a8ad8  e82316ffff           call 0x89a100
// 008a8add  8b10                 mov edx, dword ptr [eax]
// 008a8adf  03d3                 add edx, ebx
// 008a8ae1  0116                 add dword ptr [esi], edx
// 008a8ae3  5f                   pop edi
// 008a8ae4  8bc6                 mov eax, esi
// 008a8ae6  5e                   pop esi
// 008a8ae7  5d                   pop ebp
// 008a8ae8  5b                   pop ebx
// 008a8ae9  83c420               add esp, 0x20
// 008a8aec  c21400               ret 0x14
// library xtp-13.2.1-shared-mfc/Source\Controls\XTButtonTheme.cpp (function ?GetTextPosition@CXTButtonTheme@@MAE?AVCPoint@@IAAVCRect@@AAVCSize@@PAVCXTButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Controls/XTButtonTheme.cpp
