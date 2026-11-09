// from server: 100% by auto
// roc 2008-06 00401de0  unit: VCWorkspace::?$CComObject  size: 150 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00401de0
//
// 00401de0  56                   push esi
// 00401de1  8bf1                 mov esi, ecx
// 00401de3  8b06                 mov eax, dword ptr [esi]
// 00401de5  57                   push edi
// 00401de6  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00401dea  8d4c3801             lea ecx, [eax + edi + 1]
// 00401dee  3bc8                 cmp ecx, eax
// 00401df0  7e7d                 jle 0x401e6f
// 00401df2  3bcf                 cmp ecx, edi
// 00401df4  7e79                 jle 0x401e6f
// 00401df6  3b4e04               cmp ecx, dword ptr [esi + 4]
// 00401df9  7c35                 jl 0x401e30
// 00401dfb  eb03                 jmp 0x401e00
// 00401dfd  8d4900               lea ecx, [ecx]
// 00401e00  8b4604               mov eax, dword ptr [esi + 4]
// 00401e03  3dffffff3f           cmp eax, 0x3fffffff
// 00401e08  7f65                 jg 0x401e6f
// 00401e0a  03c0                 add eax, eax
// 00401e0c  3bc8                 cmp ecx, eax
// 00401e0e  894604               mov dword ptr [esi + 4], eax
// 00401e11  7ded                 jge 0x401e00
// 00401e13  33c9                 xor ecx, ecx
// 00401e15  8b5608               mov edx, dword ptr [esi + 8]
// 00401e18  7755                 ja 0x401e6f
// 00401e1a  7205                 jb 0x401e21
// 00401e1c  83f8ff               cmp eax, -1
// 00401e1f  774e                 ja 0x401e6f
// 00401e21  50                   push eax
// 00401e22  52                   push edx
// 00401e23  ff1510418000         call dword ptr [0x804110]
// 00401e29  85c0                 test eax, eax
// 00401e2b  7442                 je 0x401e6f
// 00401e2d  894608               mov dword ptr [esi + 8], eax
// 00401e30  8b06                 mov eax, dword ptr [esi]
// 00401e32  85c0                 test eax, eax
// 00401e34  7c39                 jl 0x401e6f
// 00401e36  8b5604               mov edx, dword ptr [esi + 4]
// 00401e39  3bc2                 cmp eax, edx
// 00401e3b  7d32                 jge 0x401e6f
// 00401e3d  8bca                 mov ecx, edx
// 00401e3f  2bc8                 sub ecx, eax
// 00401e41  3bca                 cmp ecx, edx
// 00401e43  7f2a                 jg 0x401e6f
// 00401e45  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00401e49  57                   push edi
// 00401e4a  52                   push edx
// 00401e4b  51                   push ecx
// 00401e4c  8b4e08               mov ecx, dword ptr [esi + 8]
// 00401e4f  03c8                 add ecx, eax
// 00401e51  51                   push ecx
// 00401e52  e8b9f9ffff           call 0x401810
// 00401e57  8b5608               mov edx, dword ptr [esi + 8]
// 00401e5a  83c410               add esp, 0x10
// 00401e5d  013e                 add dword ptr [esi], edi
// 00401e5f  8b06                 mov eax, dword ptr [esi]
// 00401e61  5f                   pop edi
// 00401e62  c6041000             mov byte ptr [eax + edx], 0
// 00401e66  b801000000           mov eax, 1
// 00401e6b  5e                   pop esi
// 00401e6c  c20800               ret 8
// 00401e6f  5f                   pop edi
// 00401e70  33c0                 xor eax, eax
// 00401e72  5e                   pop esi
// 00401e73  c20800               ret 8
// library atl-8.0/atl.cpp (function ?Append@CParseBuffer@CRegParser@ATL@@QAEHPBDH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
