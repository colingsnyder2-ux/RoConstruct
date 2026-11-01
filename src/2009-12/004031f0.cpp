// from server: 100% by auto
// roc 2009-12 004031f0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004031f0
//
// 004031f0  56                   push esi
// 004031f1  57                   push edi
// 004031f2  8b3dd4cb9800         mov edi, dword ptr [0x98cbd4]
// 004031f8  8bf1                 mov esi, ecx
// 004031fa  8d9b00000000         lea ebx, [ebx]
// 00403200  8b06                 mov eax, dword ptr [esi]
// 00403202  0fbe08               movsx ecx, byte ptr [eax]
// 00403205  83c1f7               add ecx, -9
// 00403208  83f917               cmp ecx, 0x17
// 0040320b  7715                 ja 0x403222
// 0040320d  0fb68930324000       movzx ecx, byte ptr [ecx + 0x403230]
// 00403214  ff248d28324000       jmp dword ptr [ecx*4 + 0x403228]
// 0040321b  50                   push eax
// 0040321c  ffd7                 call edi
// 0040321e  8906                 mov dword ptr [esi], eax
// 00403220  ebde                 jmp 0x403200
// 00403222  5f                   pop edi
// 00403223  5e                   pop esi
// 00403224  c3                   ret 
// 00403225  8d4900               lea ecx, [ecx]
// 00403228  1b32                 sbb esi, dword ptr [edx]
// 0040322a  40                   inc eax
// 0040322b  0022                 add byte ptr [edx], ah
// 0040322d  324000               xor al, byte ptr [eax]
// 00403230  0000                 add byte ptr [eax], al
// 00403232  0101                 add dword ptr [ecx], eax
// 00403234  0001                 add byte ptr [ecx], al
// 00403236  0101                 add dword ptr [ecx], eax
// 00403238  0101                 add dword ptr [ecx], eax
// 0040323a  0101                 add dword ptr [ecx], eax
// 0040323c  0101                 add dword ptr [ecx], eax
// 0040323e  0101                 add dword ptr [ecx], eax
// 00403240  0101                 add dword ptr [ecx], eax
// 00403242  0101                 add dword ptr [ecx], eax
// 00403244  0101                 add dword ptr [ecx], eax
// 00403246  0100                 add dword ptr [eax], eax
// library atl-8.0/atl.cpp (function ?SkipWhiteSpace@CRegParser@ATL@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
