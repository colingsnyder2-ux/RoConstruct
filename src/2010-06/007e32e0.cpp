// from server: 100% by auto
// roc 2010-06 007e32e0  unit: CXTPReportSelectedRows  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e32e0
//
// 007e32e0  53                   push ebx
// 007e32e1  55                   push ebp
// 007e32e2  8b2d04ba9e00         mov ebp, dword ptr [0x9eba04]
// 007e32e8  56                   push esi
// 007e32e9  8bd9                 mov ebx, ecx
// 007e32eb  57                   push edi
// 007e32ec  c7836c01000000000000 mov dword ptr [ebx + 0x16c], 0
// 007e32f6  be01000000           mov esi, 1
// 007e32fb  8dbb70010000         lea edi, [ebx + 0x170]
// 007e3301  8b8360040000         mov eax, dword ptr [ebx + 0x460]
// 007e3307  56                   push esi
// 007e3308  85c0                 test eax, eax
// 007e330a  7404                 je 0x7e3310
// 007e330c  ffd0                 call eax
// 007e330e  eb02                 jmp 0x7e3312
// 007e3310  ffd5                 call ebp
// 007e3312  8907                 mov dword ptr [edi], eax
// 007e3314  46                   inc esi
// 007e3315  83c704               add edi, 4
// 007e3318  83fe1e               cmp esi, 0x1e
// 007e331b  7ce4                 jl 0x7e3301
// 007e331d  5f                   pop edi
// 007e331e  5e                   pop esi
// 007e331f  5d                   pop ebp
// 007e3320  5b                   pop ebx
// 007e3321  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPColorManager.cpp (function ?RefreshSysColors@CXTPColorManager@@AAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPColorManager.cpp
