// from server: 100% by auto
// roc 2010-06 0080ade0  unit: CXTPTabClientWnd::CWorkspace  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0080ade0
//
// 0080ade0  53                   push ebx
// 0080ade1  56                   push esi
// 0080ade2  57                   push edi
// 0080ade3  8bf9                 mov edi, ecx
// 0080ade5  8b475c               mov eax, dword ptr [edi + 0x5c]
// 0080ade8  33f6                 xor esi, esi
// 0080adea  85c0                 test eax, eax
// 0080adec  7e2c                 jle 0x80ae1a
// 0080adee  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0080adf2  85f6                 test esi, esi
// 0080adf4  7c11                 jl 0x80ae07
// 0080adf6  3bf0                 cmp esi, eax
// 0080adf8  7d0d                 jge 0x80ae07
// 0080adfa  3b775c               cmp esi, dword ptr [edi + 0x5c]
// 0080adfd  7d23                 jge 0x80ae22
// 0080adff  8b4758               mov eax, dword ptr [edi + 0x58]
// 0080ae02  8b0cb0               mov ecx, dword ptr [eax + esi*4]
// 0080ae05  eb02                 jmp 0x80ae09
// 0080ae07  33c9                 xor ecx, ecx
// 0080ae09  e8e252ebff           call 0x6c00f0
// 0080ae0e  3bc3                 cmp eax, ebx
// 0080ae10  7415                 je 0x80ae27
// 0080ae12  8b475c               mov eax, dword ptr [edi + 0x5c]
// 0080ae15  46                   inc esi
// 0080ae16  3bf0                 cmp esi, eax
// 0080ae18  7cd8                 jl 0x80adf2
// 0080ae1a  5f                   pop edi
// 0080ae1b  5e                   pop esi
// 0080ae1c  33c0                 xor eax, eax
// 0080ae1e  5b                   pop ebx
// 0080ae1f  c20400               ret 4
// 0080ae22  e825cef9ff           call 0x7a7c4c
// 0080ae27  85f6                 test esi, esi
// 0080ae29  7cef                 jl 0x80ae1a
// 0080ae2b  3b775c               cmp esi, dword ptr [edi + 0x5c]
// 0080ae2e  7dea                 jge 0x80ae1a
// 0080ae30  8b4f58               mov ecx, dword ptr [edi + 0x58]
// 0080ae33  8b04b1               mov eax, dword ptr [ecx + esi*4]
// 0080ae36  5f                   pop edi
// 0080ae37  5e                   pop esi
// 0080ae38  5b                   pop ebx
// 0080ae39  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?FindItem@CWorkspace@CXTPTabClientWnd@@IBEPAVCXTPTabManagerItem@@QAUHWND__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPTabClientWnd.cpp
