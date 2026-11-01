// from server: 100% by auto
// roc 2009-12 00402fd0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 150 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00402fd0
//
// 00402fd0  56                   push esi
// 00402fd1  8bf1                 mov esi, ecx
// 00402fd3  8b06                 mov eax, dword ptr [esi]
// 00402fd5  57                   push edi
// 00402fd6  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00402fda  8d4c3801             lea ecx, [eax + edi + 1]
// 00402fde  3bc8                 cmp ecx, eax
// 00402fe0  7e7d                 jle 0x40305f
// 00402fe2  3bcf                 cmp ecx, edi
// 00402fe4  7e79                 jle 0x40305f
// 00402fe6  3b4e04               cmp ecx, dword ptr [esi + 4]
// 00402fe9  7c35                 jl 0x403020
// 00402feb  eb03                 jmp 0x402ff0
// 00402fed  8d4900               lea ecx, [ecx]
// 00402ff0  8b4604               mov eax, dword ptr [esi + 4]
// 00402ff3  3dffffff3f           cmp eax, 0x3fffffff
// 00402ff8  7f65                 jg 0x40305f
// 00402ffa  03c0                 add eax, eax
// 00402ffc  3bc8                 cmp ecx, eax
// 00402ffe  894604               mov dword ptr [esi + 4], eax
// 00403001  7ded                 jge 0x402ff0
// 00403003  33c9                 xor ecx, ecx
// 00403005  8b5608               mov edx, dword ptr [esi + 8]
// 00403008  7755                 ja 0x40305f
// 0040300a  7205                 jb 0x403011
// 0040300c  83f8ff               cmp eax, -1
// 0040300f  774e                 ja 0x40305f
// 00403011  50                   push eax
// 00403012  52                   push edx
// 00403013  ff159ce09800         call dword ptr [0x98e09c]
// 00403019  85c0                 test eax, eax
// 0040301b  7442                 je 0x40305f
// 0040301d  894608               mov dword ptr [esi + 8], eax
// 00403020  8b06                 mov eax, dword ptr [esi]
// 00403022  85c0                 test eax, eax
// 00403024  7c39                 jl 0x40305f
// 00403026  8b5604               mov edx, dword ptr [esi + 4]
// 00403029  3bc2                 cmp eax, edx
// 0040302b  7d32                 jge 0x40305f
// 0040302d  8bca                 mov ecx, edx
// 0040302f  2bc8                 sub ecx, eax
// 00403031  3bca                 cmp ecx, edx
// 00403033  7f2a                 jg 0x40305f
// 00403035  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00403039  57                   push edi
// 0040303a  52                   push edx
// 0040303b  51                   push ecx
// 0040303c  8b4e08               mov ecx, dword ptr [esi + 8]
// 0040303f  03c8                 add ecx, eax
// 00403041  51                   push ecx
// 00403042  e859fbffff           call 0x402ba0
// 00403047  8b5608               mov edx, dword ptr [esi + 8]
// 0040304a  83c410               add esp, 0x10
// 0040304d  013e                 add dword ptr [esi], edi
// 0040304f  8b06                 mov eax, dword ptr [esi]
// 00403051  5f                   pop edi
// 00403052  c6041000             mov byte ptr [eax + edx], 0
// 00403056  b801000000           mov eax, 1
// 0040305b  5e                   pop esi
// 0040305c  c20800               ret 8
// 0040305f  5f                   pop edi
// 00403060  33c0                 xor eax, eax
// 00403062  5e                   pop esi
// 00403063  c20800               ret 8
// library atl-8.0/atl.cpp (function ?Append@CParseBuffer@CRegParser@ATL@@QAEHPBDH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
