// from server: 100% by auto
// roc 2009-06 0071ad10  unit: CXTPEdit  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0071ad10
//
// 0071ad10  83ec1c               sub esp, 0x1c
// 0071ad13  56                   push esi
// 0071ad14  8b742424             mov esi, dword ptr [esp + 0x24]
// 0071ad18  57                   push edi
// 0071ad19  8bf9                 mov edi, ecx
// 0071ad1b  83fe08               cmp esi, 8
// 0071ad1e  7435                 je 0x71ad55
// 0071ad20  83fe21               cmp esi, 0x21
// 0071ad23  7205                 jb 0x71ad2a
// 0071ad25  83fe2e               cmp esi, 0x2e
// 0071ad28  762b                 jbe 0x71ad55
// 0071ad2a  83fe43               cmp esi, 0x43
// 0071ad2d  740f                 je 0x71ad3e
// 0071ad2f  83fe56               cmp esi, 0x56
// 0071ad32  740a                 je 0x71ad3e
// 0071ad34  83fe58               cmp esi, 0x58
// 0071ad37  7405                 je 0x71ad3e
// 0071ad39  83fe5a               cmp esi, 0x5a
// 0071ad3c  750d                 jne 0x71ad4b
// 0071ad3e  6a11                 push 0x11
// 0071ad40  ff1534ee8900         call dword ptr [0x89ee34]
// 0071ad46  6685c0               test ax, ax
// 0071ad49  7c0a                 jl 0x71ad55
// 0071ad4b  5f                   pop edi
// 0071ad4c  33c0                 xor eax, eax
// 0071ad4e  5e                   pop esi
// 0071ad4f  83c41c               add esp, 0x1c
// 0071ad52  c20800               ret 8
// 0071ad55  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0071ad59  8b4720               mov eax, dword ptr [edi + 0x20]
// 0071ad5c  8d542408             lea edx, [esp + 8]
// 0071ad60  894c2414             mov dword ptr [esp + 0x14], ecx
// 0071ad64  52                   push edx
// 0071ad65  8bcf                 mov ecx, edi
// 0071ad67  c744241000010000     mov dword ptr [esp + 0x10], 0x100
// 0071ad6f  8944240c             mov dword ptr [esp + 0xc], eax
// 0071ad73  89742414             mov dword ptr [esp + 0x14], esi
// 0071ad77  e83c111300           call 0x84beb8
// 0071ad7c  f7d8                 neg eax
// 0071ad7e  1bc0                 sbb eax, eax
// 0071ad80  5f                   pop edi
// 0071ad81  f7d8                 neg eax
// 0071ad83  5e                   pop esi
// 0071ad84  83c41c               add esp, 0x1c
// 0071ad87  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPControlEdit.cpp (function ?IsDialogCode@CXTPCommandBarEditCtrl@@QAEHIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlEdit.cpp
