// from server: 100% by auto
// roc 2008-06 00402000  unit: VCWorkspace::?$CComObject  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00402000
//
// 00402000  56                   push esi
// 00402001  57                   push edi
// 00402002  8b3d2c2e8000         mov edi, dword ptr [0x802e2c]
// 00402008  8bf1                 mov esi, ecx
// 0040200a  8d9b00000000         lea ebx, [ebx]
// 00402010  8b06                 mov eax, dword ptr [esi]
// 00402012  0fbe08               movsx ecx, byte ptr [eax]
// 00402015  83c1f7               add ecx, -9
// 00402018  83f917               cmp ecx, 0x17
// 0040201b  7715                 ja 0x402032
// 0040201d  0fb68940204000       movzx ecx, byte ptr [ecx + 0x402040]
// 00402024  ff248d38204000       jmp dword ptr [ecx*4 + 0x402038]
// 0040202b  50                   push eax
// 0040202c  ffd7                 call edi
// 0040202e  8906                 mov dword ptr [esi], eax
// 00402030  ebde                 jmp 0x402010
// 00402032  5f                   pop edi
// 00402033  5e                   pop esi
// 00402034  c3                   ret 
// 00402035  8d4900               lea ecx, [ecx]
// 00402038  2b20                 sub esp, dword ptr [eax]
// 0040203a  40                   inc eax
// 0040203b  0032                 add byte ptr [edx], dh
// 0040203d  204000               and byte ptr [eax], al
// 00402040  0000                 add byte ptr [eax], al
// 00402042  0101                 add dword ptr [ecx], eax
// 00402044  0001                 add byte ptr [ecx], al
// 00402046  0101                 add dword ptr [ecx], eax
// 00402048  0101                 add dword ptr [ecx], eax
// 0040204a  0101                 add dword ptr [ecx], eax
// 0040204c  0101                 add dword ptr [ecx], eax
// 0040204e  0101                 add dword ptr [ecx], eax
// 00402050  0101                 add dword ptr [ecx], eax
// 00402052  0101                 add dword ptr [ecx], eax
// 00402054  0101                 add dword ptr [ecx], eax
// 00402056  0100                 add dword ptr [eax], eax
// library atl-8.0/atl.cpp (function ?SkipWhiteSpace@CRegParser@ATL@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
