// from server: 100% by auto
// roc 2009-12 008c5f40  unit: CXTPControlCustom  size: 109 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c5f40
//
// 008c5f40  55                   push ebp
// 008c5f41  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 008c5f45  56                   push esi
// 008c5f46  57                   push edi
// 008c5f47  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008c5f4b  8bb7a0000000         mov esi, dword ptr [edi + 0xa0]
// 008c5f51  55                   push ebp
// 008c5f52  8bce                 mov ecx, esi
// 008c5f54  e8d7e7f2ff           call 0x7f4730
// 008c5f59  85c0                 test eax, eax
// 008c5f5b  740e                 je 0x8c5f6b
// 008c5f5d  55                   push ebp
// 008c5f5e  8bce                 mov ecx, esi
// 008c5f60  e8cbe7f2ff           call 0x7f4730
// 008c5f65  5f                   pop edi
// 008c5f66  5e                   pop esi
// 008c5f67  5d                   pop ebp
// 008c5f68  c20800               ret 8
// 008c5f6b  33f6                 xor esi, esi
// 008c5f6d  39b784000000         cmp dword ptr [edi + 0x84], esi
// 008c5f73  53                   push ebx
// 008c5f74  7e1f                 jle 0x8c5f95
// 008c5f76  56                   push esi
// 008c5f77  8bcf                 mov ecx, edi
// 008c5f79  e862edf4ff           call 0x814ce0
// 008c5f7e  8bd8                 mov ebx, eax
// 008c5f80  55                   push ebp
// 008c5f81  8bcb                 mov ecx, ebx
// 008c5f83  e8a8e7f2ff           call 0x7f4730
// 008c5f88  85c0                 test eax, eax
// 008c5f8a  7512                 jne 0x8c5f9e
// 008c5f8c  46                   inc esi
// 008c5f8d  3bb784000000         cmp esi, dword ptr [edi + 0x84]
// 008c5f93  7ce1                 jl 0x8c5f76
// 008c5f95  5b                   pop ebx
// 008c5f96  5f                   pop edi
// 008c5f97  5e                   pop esi
// 008c5f98  33c0                 xor eax, eax
// 008c5f9a  5d                   pop ebp
// 008c5f9b  c20800               ret 8
// 008c5f9e  55                   push ebp
// 008c5f9f  8bcb                 mov ecx, ebx
// 008c5fa1  e88ae7f2ff           call 0x7f4730
// 008c5fa6  5b                   pop ebx
// 008c5fa7  5f                   pop edi
// 008c5fa8  5e                   pop esi
// 008c5fa9  5d                   pop ebp
// 008c5faa  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPControlCustom.cpp (function ?FindChildWindow@CXTPControlCustom@@AAEPAVCWnd@@PAVCXTPCommandBars@@I@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlCustom.cpp
