// from server: 100% by auto
// roc 2009-06 007542d0  unit: CXTPReportSelectedRows  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007542d0
//
// 007542d0  53                   push ebx
// 007542d1  55                   push ebp
// 007542d2  8b2de4ee8900         mov ebp, dword ptr [0x89eee4]
// 007542d8  56                   push esi
// 007542d9  8bd9                 mov ebx, ecx
// 007542db  57                   push edi
// 007542dc  c7836c01000000000000 mov dword ptr [ebx + 0x16c], 0
// 007542e6  be01000000           mov esi, 1
// 007542eb  8dbb70010000         lea edi, [ebx + 0x170]
// 007542f1  8b8360040000         mov eax, dword ptr [ebx + 0x460]
// 007542f7  56                   push esi
// 007542f8  85c0                 test eax, eax
// 007542fa  7404                 je 0x754300
// 007542fc  ffd0                 call eax
// 007542fe  eb02                 jmp 0x754302
// 00754300  ffd5                 call ebp
// 00754302  8907                 mov dword ptr [edi], eax
// 00754304  46                   inc esi
// 00754305  83c704               add edi, 4
// 00754308  83fe1e               cmp esi, 0x1e
// 0075430b  7ce4                 jl 0x7542f1
// 0075430d  5f                   pop edi
// 0075430e  5e                   pop esi
// 0075430f  5d                   pop ebp
// 00754310  5b                   pop ebx
// 00754311  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPColorManager.cpp (function ?RefreshSysColors@CXTPColorManager@@AAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPColorManager.cpp
