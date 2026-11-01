// from server: 100% by auto
// roc 2007-03 00401e00  unit: seg_00400000  size: 150 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00401e00
//
// 00401e00  56                   push esi
// 00401e01  8bf1                 mov esi, ecx
// 00401e03  8b06                 mov eax, dword ptr [esi]
// 00401e05  57                   push edi
// 00401e06  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00401e0a  8d4c3801             lea ecx, [eax + edi + 1]
// 00401e0e  3bc8                 cmp ecx, eax
// 00401e10  7e7d                 jle 0x401e8f
// 00401e12  3bcf                 cmp ecx, edi
// 00401e14  7e79                 jle 0x401e8f
// 00401e16  3b4e04               cmp ecx, dword ptr [esi + 4]
// 00401e19  7c35                 jl 0x401e50
// 00401e1b  eb03                 jmp 0x401e20
// 00401e1d  8d4900               lea ecx, [ecx]
// 00401e20  8b4604               mov eax, dword ptr [esi + 4]
// 00401e23  3dffffff3f           cmp eax, 0x3fffffff
// 00401e28  7f65                 jg 0x401e8f
// 00401e2a  03c0                 add eax, eax
// 00401e2c  3bc8                 cmp ecx, eax
// 00401e2e  894604               mov dword ptr [esi + 4], eax
// 00401e31  7ded                 jge 0x401e20
// 00401e33  33c9                 xor ecx, ecx
// 00401e35  8b5608               mov edx, dword ptr [esi + 8]
// 00401e38  7755                 ja 0x401e8f
// 00401e3a  7205                 jb 0x401e41
// 00401e3c  83f8ff               cmp eax, -1
// 00401e3f  774e                 ja 0x401e8f
// 00401e41  50                   push eax
// 00401e42  52                   push edx
// 00401e43  ff1530f17700         call dword ptr [0x77f130]
// 00401e49  85c0                 test eax, eax
// 00401e4b  7442                 je 0x401e8f
// 00401e4d  894608               mov dword ptr [esi + 8], eax
// 00401e50  8b06                 mov eax, dword ptr [esi]
// 00401e52  85c0                 test eax, eax
// 00401e54  7c39                 jl 0x401e8f
// 00401e56  8b5604               mov edx, dword ptr [esi + 4]
// 00401e59  3bc2                 cmp eax, edx
// 00401e5b  7d32                 jge 0x401e8f
// 00401e5d  8bca                 mov ecx, edx
// 00401e5f  2bc8                 sub ecx, eax
// 00401e61  3bca                 cmp ecx, edx
// 00401e63  7f2a                 jg 0x401e8f
// 00401e65  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00401e69  57                   push edi
// 00401e6a  52                   push edx
// 00401e6b  51                   push ecx
// 00401e6c  8b4e08               mov ecx, dword ptr [esi + 8]
// 00401e6f  03c8                 add ecx, eax
// 00401e71  51                   push ecx
// 00401e72  e819faffff           call 0x401890
// 00401e77  8b5608               mov edx, dword ptr [esi + 8]
// 00401e7a  83c410               add esp, 0x10
// 00401e7d  013e                 add dword ptr [esi], edi
// 00401e7f  8b06                 mov eax, dword ptr [esi]
// 00401e81  5f                   pop edi
// 00401e82  c6041000             mov byte ptr [eax + edx], 0
// 00401e86  b801000000           mov eax, 1
// 00401e8b  5e                   pop esi
// 00401e8c  c20800               ret 8
// 00401e8f  5f                   pop edi
// 00401e90  33c0                 xor eax, eax
// 00401e92  5e                   pop esi
// 00401e93  c20800               ret 8
// library atl-8.0/atl.cpp (function ?Append@CParseBuffer@CRegParser@ATL@@QAEHPBDH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
