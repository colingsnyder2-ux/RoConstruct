// from server: 100% by auto
// roc 2009-06 0077bda0  unit: CXTPTabClientWnd::CWorkspace  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077bda0
//
// 0077bda0  53                   push ebx
// 0077bda1  56                   push esi
// 0077bda2  57                   push edi
// 0077bda3  8bf9                 mov edi, ecx
// 0077bda5  8b475c               mov eax, dword ptr [edi + 0x5c]
// 0077bda8  33f6                 xor esi, esi
// 0077bdaa  85c0                 test eax, eax
// 0077bdac  7e2c                 jle 0x77bdda
// 0077bdae  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0077bdb2  85f6                 test esi, esi
// 0077bdb4  7c11                 jl 0x77bdc7
// 0077bdb6  3bf0                 cmp esi, eax
// 0077bdb8  7d0d                 jge 0x77bdc7
// 0077bdba  3b775c               cmp esi, dword ptr [edi + 0x5c]
// 0077bdbd  7d23                 jge 0x77bde2
// 0077bdbf  8b4758               mov eax, dword ptr [edi + 0x58]
// 0077bdc2  8b0cb0               mov ecx, dword ptr [eax + esi*4]
// 0077bdc5  eb02                 jmp 0x77bdc9
// 0077bdc7  33c9                 xor ecx, ecx
// 0077bdc9  e80258f3ff           call 0x6b15d0
// 0077bdce  3bc3                 cmp eax, ebx
// 0077bdd0  7415                 je 0x77bde7
// 0077bdd2  8b475c               mov eax, dword ptr [edi + 0x5c]
// 0077bdd5  46                   inc esi
// 0077bdd6  3bf0                 cmp esi, eax
// 0077bdd8  7cd8                 jl 0x77bdb2
// 0077bdda  5f                   pop edi
// 0077bddb  5e                   pop esi
// 0077bddc  33c0                 xor eax, eax
// 0077bdde  5b                   pop ebx
// 0077bddf  c20400               ret 4
// 0077bde2  e8fdcef9ff           call 0x718ce4
// 0077bde7  85f6                 test esi, esi
// 0077bde9  7cef                 jl 0x77bdda
// 0077bdeb  3b775c               cmp esi, dword ptr [edi + 0x5c]
// 0077bdee  7dea                 jge 0x77bdda
// 0077bdf0  8b4f58               mov ecx, dword ptr [edi + 0x58]
// 0077bdf3  8b04b1               mov eax, dword ptr [ecx + esi*4]
// 0077bdf6  5f                   pop edi
// 0077bdf7  5e                   pop esi
// 0077bdf8  5b                   pop ebx
// 0077bdf9  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?FindItem@CWorkspace@CXTPTabClientWnd@@IBEPAVCXTPTabManagerItem@@QAUHWND__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
