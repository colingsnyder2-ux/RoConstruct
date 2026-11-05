// from server: 100% by auto
// roc 2011-06 00403a10  unit: RBX::VRenderHooksService::?$FactoryProduct::Creator  size: 150 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00403a10
//
// 00403a10  56                   push esi
// 00403a11  8bf1                 mov esi, ecx
// 00403a13  8b06                 mov eax, dword ptr [esi]
// 00403a15  57                   push edi
// 00403a16  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00403a1a  8d4c3801             lea ecx, [eax + edi + 1]
// 00403a1e  3bc8                 cmp ecx, eax
// 00403a20  7e7d                 jle 0x403a9f
// 00403a22  3bcf                 cmp ecx, edi
// 00403a24  7e79                 jle 0x403a9f
// 00403a26  3b4e04               cmp ecx, dword ptr [esi + 4]
// 00403a29  7c35                 jl 0x403a60
// 00403a2b  eb03                 jmp 0x403a30
// 00403a2d  8d4900               lea ecx, [ecx]
// 00403a30  8b4604               mov eax, dword ptr [esi + 4]
// 00403a33  3dffffff3f           cmp eax, 0x3fffffff
// 00403a38  7f65                 jg 0x403a9f
// 00403a3a  03c0                 add eax, eax
// 00403a3c  3bc8                 cmp ecx, eax
// 00403a3e  894604               mov dword ptr [esi + 4], eax
// 00403a41  7ded                 jge 0x403a30
// 00403a43  33c9                 xor ecx, ecx
// 00403a45  8b5608               mov edx, dword ptr [esi + 8]
// 00403a48  7755                 ja 0x403a9f
// 00403a4a  7205                 jb 0x403a51
// 00403a4c  83f8ff               cmp eax, -1
// 00403a4f  774e                 ja 0x403a9f
// 00403a51  50                   push eax
// 00403a52  52                   push edx
// 00403a53  ff157830a400         call dword ptr [0xa43078]
// 00403a59  85c0                 test eax, eax
// 00403a5b  7442                 je 0x403a9f
// 00403a5d  894608               mov dword ptr [esi + 8], eax
// 00403a60  8b06                 mov eax, dword ptr [esi]
// 00403a62  85c0                 test eax, eax
// 00403a64  7c39                 jl 0x403a9f
// 00403a66  8b5604               mov edx, dword ptr [esi + 4]
// 00403a69  3bc2                 cmp eax, edx
// 00403a6b  7d32                 jge 0x403a9f
// 00403a6d  8bca                 mov ecx, edx
// 00403a6f  2bc8                 sub ecx, eax
// 00403a71  3bca                 cmp ecx, edx
// 00403a73  7f2a                 jg 0x403a9f
// 00403a75  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00403a79  57                   push edi
// 00403a7a  52                   push edx
// 00403a7b  51                   push ecx
// 00403a7c  8b4e08               mov ecx, dword ptr [esi + 8]
// 00403a7f  03c8                 add ecx, eax
// 00403a81  51                   push ecx
// 00403a82  e839fbffff           call 0x4035c0
// 00403a87  8b5608               mov edx, dword ptr [esi + 8]
// 00403a8a  83c410               add esp, 0x10
// 00403a8d  013e                 add dword ptr [esi], edi
// 00403a8f  8b06                 mov eax, dword ptr [esi]
// 00403a91  5f                   pop edi
// 00403a92  c6041000             mov byte ptr [eax + edx], 0
// 00403a96  b801000000           mov eax, 1
// 00403a9b  5e                   pop esi
// 00403a9c  c20800               ret 8
// 00403a9f  5f                   pop edi
// 00403aa0  33c0                 xor eax, eax
// 00403aa2  5e                   pop esi
// 00403aa3  c20800               ret 8
// library atl-8.0/atl.cpp (function ?Append@CParseBuffer@CRegParser@ATL@@QAEHPBDH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
