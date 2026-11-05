// from server: 100% by auto
// roc 2009-06 00403300  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 150 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00403300
//
// 00403300  56                   push esi
// 00403301  8bf1                 mov esi, ecx
// 00403303  8b06                 mov eax, dword ptr [esi]
// 00403305  57                   push edi
// 00403306  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0040330a  8d4c3801             lea ecx, [eax + edi + 1]
// 0040330e  3bc8                 cmp ecx, eax
// 00403310  7e7d                 jle 0x40338f
// 00403312  3bcf                 cmp ecx, edi
// 00403314  7e79                 jle 0x40338f
// 00403316  3b4e04               cmp ecx, dword ptr [esi + 4]
// 00403319  7c35                 jl 0x403350
// 0040331b  eb03                 jmp 0x403320
// 0040331d  8d4900               lea ecx, [ecx]
// 00403320  8b4604               mov eax, dword ptr [esi + 4]
// 00403323  3dffffff3f           cmp eax, 0x3fffffff
// 00403328  7f65                 jg 0x40338f
// 0040332a  03c0                 add eax, eax
// 0040332c  3bc8                 cmp ecx, eax
// 0040332e  894604               mov dword ptr [esi + 4], eax
// 00403331  7ded                 jge 0x403320
// 00403333  33c9                 xor ecx, ecx
// 00403335  8b5608               mov edx, dword ptr [esi + 8]
// 00403338  7755                 ja 0x40338f
// 0040333a  7205                 jb 0x403341
// 0040333c  83f8ff               cmp eax, -1
// 0040333f  774e                 ja 0x40338f
// 00403341  50                   push eax
// 00403342  52                   push edx
// 00403343  ff1508038a00         call dword ptr [0x8a0308]
// 00403349  85c0                 test eax, eax
// 0040334b  7442                 je 0x40338f
// 0040334d  894608               mov dword ptr [esi + 8], eax
// 00403350  8b06                 mov eax, dword ptr [esi]
// 00403352  85c0                 test eax, eax
// 00403354  7c39                 jl 0x40338f
// 00403356  8b5604               mov edx, dword ptr [esi + 4]
// 00403359  3bc2                 cmp eax, edx
// 0040335b  7d32                 jge 0x40338f
// 0040335d  8bca                 mov ecx, edx
// 0040335f  2bc8                 sub ecx, eax
// 00403361  3bca                 cmp ecx, edx
// 00403363  7f2a                 jg 0x40338f
// 00403365  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00403369  57                   push edi
// 0040336a  52                   push edx
// 0040336b  51                   push ecx
// 0040336c  8b4e08               mov ecx, dword ptr [esi + 8]
// 0040336f  03c8                 add ecx, eax
// 00403371  51                   push ecx
// 00403372  e859fbffff           call 0x402ed0
// 00403377  8b5608               mov edx, dword ptr [esi + 8]
// 0040337a  83c410               add esp, 0x10
// 0040337d  013e                 add dword ptr [esi], edi
// 0040337f  8b06                 mov eax, dword ptr [esi]
// 00403381  5f                   pop edi
// 00403382  c6041000             mov byte ptr [eax + edx], 0
// 00403386  b801000000           mov eax, 1
// 0040338b  5e                   pop esi
// 0040338c  c20800               ret 8
// 0040338f  5f                   pop edi
// 00403390  33c0                 xor eax, eax
// 00403392  5e                   pop esi
// 00403393  c20800               ret 8
// library atl-8.0/atl.cpp (function ?Append@CParseBuffer@CRegParser@ATL@@QAEHPBDH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
