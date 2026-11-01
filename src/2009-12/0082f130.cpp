// from server: 100% by auto
// roc 2009-12 0082f130  unit: CXTPReportSelectedRows  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0082f130
//
// 0082f130  53                   push ebx
// 0082f131  55                   push ebp
// 0082f132  8b2dd8ca9800         mov ebp, dword ptr [0x98cad8]
// 0082f138  56                   push esi
// 0082f139  8bd9                 mov ebx, ecx
// 0082f13b  57                   push edi
// 0082f13c  c7836c01000000000000 mov dword ptr [ebx + 0x16c], 0
// 0082f146  be01000000           mov esi, 1
// 0082f14b  8dbb70010000         lea edi, [ebx + 0x170]
// 0082f151  8b8360040000         mov eax, dword ptr [ebx + 0x460]
// 0082f157  56                   push esi
// 0082f158  85c0                 test eax, eax
// 0082f15a  7404                 je 0x82f160
// 0082f15c  ffd0                 call eax
// 0082f15e  eb02                 jmp 0x82f162
// 0082f160  ffd5                 call ebp
// 0082f162  8907                 mov dword ptr [edi], eax
// 0082f164  46                   inc esi
// 0082f165  83c704               add edi, 4
// 0082f168  83fe1e               cmp esi, 0x1e
// 0082f16b  7ce4                 jl 0x82f151
// 0082f16d  5f                   pop edi
// 0082f16e  5e                   pop esi
// 0082f16f  5d                   pop ebp
// 0082f170  5b                   pop ebx
// 0082f171  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPColorManager.cpp (function ?RefreshSysColors@CXTPColorManager@@AAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPColorManager.cpp
