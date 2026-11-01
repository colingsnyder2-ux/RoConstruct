// from server: 100% by auto
// roc 2007-08 00401e10  unit: VCWorkspace::?$CComObject  size: 150 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00401e10
//
// 00401e10  56                   push esi
// 00401e11  8bf1                 mov esi, ecx
// 00401e13  8b06                 mov eax, dword ptr [esi]
// 00401e15  57                   push edi
// 00401e16  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00401e1a  8d4c3801             lea ecx, [eax + edi + 1]
// 00401e1e  3bc8                 cmp ecx, eax
// 00401e20  7e7d                 jle 0x401e9f
// 00401e22  3bcf                 cmp ecx, edi
// 00401e24  7e79                 jle 0x401e9f
// 00401e26  3b4e04               cmp ecx, dword ptr [esi + 4]
// 00401e29  7c35                 jl 0x401e60
// 00401e2b  eb03                 jmp 0x401e30
// 00401e2d  8d4900               lea ecx, [ecx]
// 00401e30  8b4604               mov eax, dword ptr [esi + 4]
// 00401e33  3dffffff3f           cmp eax, 0x3fffffff
// 00401e38  7f65                 jg 0x401e9f
// 00401e3a  03c0                 add eax, eax
// 00401e3c  3bc8                 cmp ecx, eax
// 00401e3e  894604               mov dword ptr [esi + 4], eax
// 00401e41  7ded                 jge 0x401e30
// 00401e43  33c9                 xor ecx, ecx
// 00401e45  8b5608               mov edx, dword ptr [esi + 8]
// 00401e48  7755                 ja 0x401e9f
// 00401e4a  7205                 jb 0x401e51
// 00401e4c  83f8ff               cmp eax, -1
// 00401e4f  774e                 ja 0x401e9f
// 00401e51  50                   push eax
// 00401e52  52                   push edx
// 00401e53  ff1520f07700         call dword ptr [0x77f020]
// 00401e59  85c0                 test eax, eax
// 00401e5b  7442                 je 0x401e9f
// 00401e5d  894608               mov dword ptr [esi + 8], eax
// 00401e60  8b06                 mov eax, dword ptr [esi]
// 00401e62  85c0                 test eax, eax
// 00401e64  7c39                 jl 0x401e9f
// 00401e66  8b5604               mov edx, dword ptr [esi + 4]
// 00401e69  3bc2                 cmp eax, edx
// 00401e6b  7d32                 jge 0x401e9f
// 00401e6d  8bca                 mov ecx, edx
// 00401e6f  2bc8                 sub ecx, eax
// 00401e71  3bca                 cmp ecx, edx
// 00401e73  7f2a                 jg 0x401e9f
// 00401e75  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00401e79  57                   push edi
// 00401e7a  52                   push edx
// 00401e7b  51                   push ecx
// 00401e7c  8b4e08               mov ecx, dword ptr [esi + 8]
// 00401e7f  03c8                 add ecx, eax
// 00401e81  51                   push ecx
// 00401e82  e8f9f9ffff           call 0x401880
// 00401e87  8b5608               mov edx, dword ptr [esi + 8]
// 00401e8a  83c410               add esp, 0x10
// 00401e8d  013e                 add dword ptr [esi], edi
// 00401e8f  8b06                 mov eax, dword ptr [esi]
// 00401e91  5f                   pop edi
// 00401e92  c6041000             mov byte ptr [eax + edx], 0
// 00401e96  b801000000           mov eax, 1
// 00401e9b  5e                   pop esi
// 00401e9c  c20800               ret 8
// 00401e9f  5f                   pop edi
// 00401ea0  33c0                 xor eax, eax
// 00401ea2  5e                   pop esi
// 00401ea3  c20800               ret 8
// library atl-8.0/atl.cpp (function ?Append@CParseBuffer@CRegParser@ATL@@QAEHPBDH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
