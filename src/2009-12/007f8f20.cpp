// from server: 100% by auto
// roc 2009-12 007f8f20  unit: CXTPEdit  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007f8f20
//
// 007f8f20  83ec1c               sub esp, 0x1c
// 007f8f23  56                   push esi
// 007f8f24  8b742424             mov esi, dword ptr [esp + 0x24]
// 007f8f28  57                   push edi
// 007f8f29  8bf9                 mov edi, ecx
// 007f8f2b  83fe08               cmp esi, 8
// 007f8f2e  7435                 je 0x7f8f65
// 007f8f30  83fe21               cmp esi, 0x21
// 007f8f33  7205                 jb 0x7f8f3a
// 007f8f35  83fe2e               cmp esi, 0x2e
// 007f8f38  762b                 jbe 0x7f8f65
// 007f8f3a  83fe43               cmp esi, 0x43
// 007f8f3d  740f                 je 0x7f8f4e
// 007f8f3f  83fe56               cmp esi, 0x56
// 007f8f42  740a                 je 0x7f8f4e
// 007f8f44  83fe58               cmp esi, 0x58
// 007f8f47  7405                 je 0x7f8f4e
// 007f8f49  83fe5a               cmp esi, 0x5a
// 007f8f4c  750d                 jne 0x7f8f5b
// 007f8f4e  6a11                 push 0x11
// 007f8f50  ff1530cc9800         call dword ptr [0x98cc30]
// 007f8f56  6685c0               test ax, ax
// 007f8f59  7c0a                 jl 0x7f8f65
// 007f8f5b  5f                   pop edi
// 007f8f5c  33c0                 xor eax, eax
// 007f8f5e  5e                   pop esi
// 007f8f5f  83c41c               add esp, 0x1c
// 007f8f62  c20800               ret 8
// 007f8f65  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 007f8f69  8b4720               mov eax, dword ptr [edi + 0x20]
// 007f8f6c  8d542408             lea edx, [esp + 8]
// 007f8f70  894c2414             mov dword ptr [esp + 0x14], ecx
// 007f8f74  52                   push edx
// 007f8f75  8bcf                 mov ecx, edi
// 007f8f77  c744241000010000     mov dword ptr [esp + 0x10], 0x100
// 007f8f7f  8944240c             mov dword ptr [esp + 0xc], eax
// 007f8f83  89742414             mov dword ptr [esp + 0x14], esi
// 007f8f87  e8ced41200           call 0x92645a
// 007f8f8c  f7d8                 neg eax
// 007f8f8e  1bc0                 sbb eax, eax
// 007f8f90  5f                   pop edi
// 007f8f91  f7d8                 neg eax
// 007f8f93  5e                   pop esi
// 007f8f94  83c41c               add esp, 0x1c
// 007f8f97  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPControlEdit.cpp (function ?IsDialogCode@CXTPCommandBarEditCtrl@@QAEHIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlEdit.cpp
