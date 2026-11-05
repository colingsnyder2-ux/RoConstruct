// from server: 100% by auto
// roc 2010-06 0087a100  unit: CXTPControlCustom  size: 109 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0087a100
//
// 0087a100  55                   push ebp
// 0087a101  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 0087a105  56                   push esi
// 0087a106  57                   push edi
// 0087a107  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0087a10b  8bb7a0000000         mov esi, dword ptr [edi + 0xa0]
// 0087a111  55                   push ebp
// 0087a112  8bce                 mov ecx, esi
// 0087a114  e851e7f2ff           call 0x7a886a
// 0087a119  85c0                 test eax, eax
// 0087a11b  740e                 je 0x87a12b
// 0087a11d  55                   push ebp
// 0087a11e  8bce                 mov ecx, esi
// 0087a120  e845e7f2ff           call 0x7a886a
// 0087a125  5f                   pop edi
// 0087a126  5e                   pop esi
// 0087a127  5d                   pop ebp
// 0087a128  c20800               ret 8
// 0087a12b  33f6                 xor esi, esi
// 0087a12d  39b784000000         cmp dword ptr [edi + 0x84], esi
// 0087a133  53                   push ebx
// 0087a134  7e1f                 jle 0x87a155
// 0087a136  56                   push esi
// 0087a137  8bcf                 mov ecx, edi
// 0087a139  e872ecf4ff           call 0x7c8db0
// 0087a13e  8bd8                 mov ebx, eax
// 0087a140  55                   push ebp
// 0087a141  8bcb                 mov ecx, ebx
// 0087a143  e822e7f2ff           call 0x7a886a
// 0087a148  85c0                 test eax, eax
// 0087a14a  7512                 jne 0x87a15e
// 0087a14c  46                   inc esi
// 0087a14d  3bb784000000         cmp esi, dword ptr [edi + 0x84]
// 0087a153  7ce1                 jl 0x87a136
// 0087a155  5b                   pop ebx
// 0087a156  5f                   pop edi
// 0087a157  5e                   pop esi
// 0087a158  33c0                 xor eax, eax
// 0087a15a  5d                   pop ebp
// 0087a15b  c20800               ret 8
// 0087a15e  55                   push ebp
// 0087a15f  8bcb                 mov ecx, ebx
// 0087a161  e804e7f2ff           call 0x7a886a
// 0087a166  5b                   pop ebx
// 0087a167  5f                   pop edi
// 0087a168  5e                   pop esi
// 0087a169  5d                   pop ebp
// 0087a16a  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPControlCustom.cpp (function ?FindChildWindow@CXTPControlCustom@@AAEPAVCWnd@@PAVCXTPCommandBars@@I@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlCustom.cpp
