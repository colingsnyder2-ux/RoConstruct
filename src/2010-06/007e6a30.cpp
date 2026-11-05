// from server: 100% by auto
// roc 2010-06 007e6a30  unit: CRobloxTreeCtrl  size: 232 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e6a30
//
// 007e6a30  837c240800           cmp dword ptr [esp + 8], 0
// 007e6a35  56                   push esi
// 007e6a36  57                   push edi
// 007e6a37  8bf1                 mov esi, ecx
// 007e6a39  0f8491000000         je 0x7e6ad0
// 007e6a3f  53                   push ebx
// 007e6a40  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 007e6a44  f6c304               test bl, 4
// 007e6a47  744a                 je 0x7e6a93
// 007e6a49  837e0c00             cmp dword ptr [esi + 0xc], 0
// 007e6a4d  7519                 jne 0x7e6a68
// 007e6a4f  8b4634               mov eax, dword ptr [esi + 0x34]
// 007e6a52  8b4020               mov eax, dword ptr [eax + 0x20]
// 007e6a55  6a00                 push 0
// 007e6a57  6a09                 push 9
// 007e6a59  680a110000           push 0x110a
// 007e6a5e  50                   push eax
// 007e6a5f  ff1554ba9e00         call dword ptr [0x9eba54]
// 007e6a65  89460c               mov dword ptr [esi + 0xc], eax
// 007e6a68  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007e6a6c  6a01                 push 1
// 007e6a6e  6a01                 push 1
// 007e6a70  57                   push edi
// 007e6a71  8bce                 mov ecx, esi
// 007e6a73  e898f8ffff           call 0x7e6310
// 007e6a78  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007e6a7b  c1eb03               shr ebx, 3
// 007e6a7e  f7d3                 not ebx
// 007e6a80  83e301               and ebx, 1
// 007e6a83  53                   push ebx
// 007e6a84  57                   push edi
// 007e6a85  51                   push ecx
// 007e6a86  8bce                 mov ecx, esi
// 007e6a88  e853feffff           call 0x7e68e0
// 007e6a8d  5b                   pop ebx
// 007e6a8e  5f                   pop edi
// 007e6a8f  5e                   pop esi
// 007e6a90  c20c00               ret 0xc
// 007e6a93  f6c308               test bl, 8
// 007e6a96  752b                 jne 0x7e6ac3
// 007e6a98  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007e6a9c  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007e6a9f  6a02                 push 2
// 007e6aa1  57                   push edi
// 007e6aa2  e89b651900           call 0x97d042
// 007e6aa7  a802                 test al, 2
// 007e6aa9  750c                 jne 0x7e6ab7
// 007e6aab  8b16                 mov edx, dword ptr [esi]
// 007e6aad  8b4250               mov eax, dword ptr [edx + 0x50]
// 007e6ab0  57                   push edi
// 007e6ab1  6a00                 push 0
// 007e6ab3  8bce                 mov ecx, esi
// 007e6ab5  ffd0                 call eax
// 007e6ab7  6a03                 push 3
// 007e6ab9  6a03                 push 3
// 007e6abb  57                   push edi
// 007e6abc  8bce                 mov ecx, esi
// 007e6abe  e84df8ffff           call 0x7e6310
// 007e6ac3  5b                   pop ebx
// 007e6ac4  5f                   pop edi
// 007e6ac5  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 007e6acc  5e                   pop esi
// 007e6acd  c20c00               ret 0xc
// 007e6ad0  8a442414             mov al, byte ptr [esp + 0x14]
// 007e6ad4  a80c                 test al, 0xc
// 007e6ad6  7410                 je 0x7e6ae8
// 007e6ad8  a804                 test al, 4
// 007e6ada  75b2                 jne 0x7e6a8e
// 007e6adc  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007e6ae0  5f                   pop edi
// 007e6ae1  894e0c               mov dword ptr [esi + 0xc], ecx
// 007e6ae4  5e                   pop esi
// 007e6ae5  c20c00               ret 0xc
// 007e6ae8  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007e6aec  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007e6aef  6a02                 push 2
// 007e6af1  57                   push edi
// 007e6af2  e84b651900           call 0x97d042
// 007e6af7  a802                 test al, 2
// 007e6af9  750c                 jne 0x7e6b07
// 007e6afb  8b16                 mov edx, dword ptr [esi]
// 007e6afd  8b4250               mov eax, dword ptr [edx + 0x50]
// 007e6b00  57                   push edi
// 007e6b01  6a00                 push 0
// 007e6b03  8bce                 mov ecx, esi
// 007e6b05  ffd0                 call eax
// 007e6b07  6a03                 push 3
// 007e6b09  6a03                 push 3
// 007e6b0b  57                   push edi
// 007e6b0c  8bce                 mov ecx, esi
// 007e6b0e  e8fdf7ffff           call 0x7e6310
// 007e6b13  5f                   pop edi
// 007e6b14  5e                   pop esi
// 007e6b15  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?DoPreSelection@CXTTreeBase@@MAEXPAU_TREEITEM@@HI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
