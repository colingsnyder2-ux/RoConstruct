// from server: 100% by auto
// roc 2010-06 007b3cf0  unit: CXTPEdit  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007b3cf0
//
// 007b3cf0  83ec1c               sub esp, 0x1c
// 007b3cf3  56                   push esi
// 007b3cf4  8b742424             mov esi, dword ptr [esp + 0x24]
// 007b3cf8  57                   push edi
// 007b3cf9  8bf9                 mov edi, ecx
// 007b3cfb  83fe08               cmp esi, 8
// 007b3cfe  7435                 je 0x7b3d35
// 007b3d00  83fe21               cmp esi, 0x21
// 007b3d03  7205                 jb 0x7b3d0a
// 007b3d05  83fe2e               cmp esi, 0x2e
// 007b3d08  762b                 jbe 0x7b3d35
// 007b3d0a  83fe43               cmp esi, 0x43
// 007b3d0d  740f                 je 0x7b3d1e
// 007b3d0f  83fe56               cmp esi, 0x56
// 007b3d12  740a                 je 0x7b3d1e
// 007b3d14  83fe58               cmp esi, 0x58
// 007b3d17  7405                 je 0x7b3d1e
// 007b3d19  83fe5a               cmp esi, 0x5a
// 007b3d1c  750d                 jne 0x7b3d2b
// 007b3d1e  6a11                 push 0x11
// 007b3d20  ff157cbc9e00         call dword ptr [0x9ebc7c]
// 007b3d26  6685c0               test ax, ax
// 007b3d29  7c0a                 jl 0x7b3d35
// 007b3d2b  5f                   pop edi
// 007b3d2c  33c0                 xor eax, eax
// 007b3d2e  5e                   pop esi
// 007b3d2f  83c41c               add esp, 0x1c
// 007b3d32  c20800               ret 8
// 007b3d35  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 007b3d39  8b4720               mov eax, dword ptr [edi + 0x20]
// 007b3d3c  8d542408             lea edx, [esp + 8]
// 007b3d40  894c2414             mov dword ptr [esp + 0x14], ecx
// 007b3d44  52                   push edx
// 007b3d45  8bcf                 mov ecx, edi
// 007b3d47  c744241000010000     mov dword ptr [esp + 0x10], 0x100
// 007b3d4f  8944240c             mov dword ptr [esp + 0xc], eax
// 007b3d53  89742414             mov dword ptr [esp + 0x14], esi
// 007b3d57  e86a901c00           call 0x97cdc6
// 007b3d5c  f7d8                 neg eax
// 007b3d5e  1bc0                 sbb eax, eax
// 007b3d60  5f                   pop edi
// 007b3d61  f7d8                 neg eax
// 007b3d63  5e                   pop esi
// 007b3d64  83c41c               add esp, 0x1c
// 007b3d67  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ?IsDialogCode@CXTPCommandBarEditCtrl@@QAEHIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlComboBox.cpp
