// from server: 100% by auto
// roc 2009-06 007579f0  unit: CRobloxTreeCtrl  size: 232 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007579f0
//
// 007579f0  837c240800           cmp dword ptr [esp + 8], 0
// 007579f5  56                   push esi
// 007579f6  57                   push edi
// 007579f7  8bf1                 mov esi, ecx
// 007579f9  0f8491000000         je 0x757a90
// 007579ff  53                   push ebx
// 00757a00  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00757a04  f6c304               test bl, 4
// 00757a07  744a                 je 0x757a53
// 00757a09  837e0c00             cmp dword ptr [esi + 0xc], 0
// 00757a0d  7519                 jne 0x757a28
// 00757a0f  8b4634               mov eax, dword ptr [esi + 0x34]
// 00757a12  8b4020               mov eax, dword ptr [eax + 0x20]
// 00757a15  6a00                 push 0
// 00757a17  6a09                 push 9
// 00757a19  680a110000           push 0x110a
// 00757a1e  50                   push eax
// 00757a1f  ff1590ee8900         call dword ptr [0x89ee90]
// 00757a25  89460c               mov dword ptr [esi + 0xc], eax
// 00757a28  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00757a2c  6a01                 push 1
// 00757a2e  6a01                 push 1
// 00757a30  57                   push edi
// 00757a31  8bce                 mov ecx, esi
// 00757a33  e898f8ffff           call 0x7572d0
// 00757a38  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00757a3b  c1eb03               shr ebx, 3
// 00757a3e  f7d3                 not ebx
// 00757a40  83e301               and ebx, 1
// 00757a43  53                   push ebx
// 00757a44  57                   push edi
// 00757a45  51                   push ecx
// 00757a46  8bce                 mov ecx, esi
// 00757a48  e853feffff           call 0x7578a0
// 00757a4d  5b                   pop ebx
// 00757a4e  5f                   pop edi
// 00757a4f  5e                   pop esi
// 00757a50  c20c00               ret 0xc
// 00757a53  f6c308               test bl, 8
// 00757a56  752b                 jne 0x757a83
// 00757a58  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00757a5c  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00757a5f  6a02                 push 2
// 00757a61  57                   push edi
// 00757a62  e833470f00           call 0x84c19a
// 00757a67  a802                 test al, 2
// 00757a69  750c                 jne 0x757a77
// 00757a6b  8b16                 mov edx, dword ptr [esi]
// 00757a6d  8b4250               mov eax, dword ptr [edx + 0x50]
// 00757a70  57                   push edi
// 00757a71  6a00                 push 0
// 00757a73  8bce                 mov ecx, esi
// 00757a75  ffd0                 call eax
// 00757a77  6a03                 push 3
// 00757a79  6a03                 push 3
// 00757a7b  57                   push edi
// 00757a7c  8bce                 mov ecx, esi
// 00757a7e  e84df8ffff           call 0x7572d0
// 00757a83  5b                   pop ebx
// 00757a84  5f                   pop edi
// 00757a85  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 00757a8c  5e                   pop esi
// 00757a8d  c20c00               ret 0xc
// 00757a90  8a442414             mov al, byte ptr [esp + 0x14]
// 00757a94  a80c                 test al, 0xc
// 00757a96  7410                 je 0x757aa8
// 00757a98  a804                 test al, 4
// 00757a9a  75b2                 jne 0x757a4e
// 00757a9c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00757aa0  5f                   pop edi
// 00757aa1  894e0c               mov dword ptr [esi + 0xc], ecx
// 00757aa4  5e                   pop esi
// 00757aa5  c20c00               ret 0xc
// 00757aa8  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00757aac  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00757aaf  6a02                 push 2
// 00757ab1  57                   push edi
// 00757ab2  e8e3460f00           call 0x84c19a
// 00757ab7  a802                 test al, 2
// 00757ab9  750c                 jne 0x757ac7
// 00757abb  8b16                 mov edx, dword ptr [esi]
// 00757abd  8b4250               mov eax, dword ptr [edx + 0x50]
// 00757ac0  57                   push edi
// 00757ac1  6a00                 push 0
// 00757ac3  8bce                 mov ecx, esi
// 00757ac5  ffd0                 call eax
// 00757ac7  6a03                 push 3
// 00757ac9  6a03                 push 3
// 00757acb  57                   push edi
// 00757acc  8bce                 mov ecx, esi
// 00757ace  e8fdf7ffff           call 0x7572d0
// 00757ad3  5f                   pop edi
// 00757ad4  5e                   pop esi
// 00757ad5  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?DoPreSelection@CXTPTreeBase@@MAEXPAU_TREEITEM@@HI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
