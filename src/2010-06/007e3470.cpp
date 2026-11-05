// from server: 100% by auto
// roc 2010-06 007e3470  unit: CXTPReportSelectedRows  size: 100 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e3470
//
// 007e3470  8b442404             mov eax, dword ptr [esp + 4]
// 007e3474  85c0                 test eax, eax
// 007e3476  7417                 je 0x7e348f
// 007e3478  6a0c                 push 0xc
// 007e347a  50                   push eax
// 007e347b  ff15b4a09e00         call dword ptr [0x9ea0b4]
// 007e3481  48                   dec eax
// 007e3482  b907000000           mov ecx, 7
// 007e3487  3bc8                 cmp ecx, eax
// 007e3489  1bc0                 sbb eax, eax
// 007e348b  40                   inc eax
// 007e348c  c20400               ret 4
// 007e348f  53                   push ebx
// 007e3490  8b1d74ba9e00         mov ebx, dword ptr [0x9eba74]
// 007e3496  56                   push esi
// 007e3497  ffd3                 call ebx
// 007e3499  50                   push eax
// 007e349a  ff1570ba9e00         call dword ptr [0x9eba70]
// 007e34a0  8bf0                 mov esi, eax
// 007e34a2  85f6                 test esi, esi
// 007e34a4  7427                 je 0x7e34cd
// 007e34a6  57                   push edi
// 007e34a7  6a0c                 push 0xc
// 007e34a9  56                   push esi
// 007e34aa  ff15b4a09e00         call dword ptr [0x9ea0b4]
// 007e34b0  56                   push esi
// 007e34b1  8bf8                 mov edi, eax
// 007e34b3  ffd3                 call ebx
// 007e34b5  50                   push eax
// 007e34b6  ff1568ba9e00         call dword ptr [0x9eba68]
// 007e34bc  4f                   dec edi
// 007e34bd  ba07000000           mov edx, 7
// 007e34c2  3bd7                 cmp edx, edi
// 007e34c4  5f                   pop edi
// 007e34c5  1bc0                 sbb eax, eax
// 007e34c7  5e                   pop esi
// 007e34c8  40                   inc eax
// 007e34c9  5b                   pop ebx
// 007e34ca  c20400               ret 4
// 007e34cd  5e                   pop esi
// 007e34ce  33c0                 xor eax, eax
// 007e34d0  5b                   pop ebx
// 007e34d1  c20400               ret 4
// library xtp-13.2.1/Source\Common\XTPColorManager.cpp (function ?IsLowResolution@CXTPColorManager@@QAEHPAUHDC__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPColorManager.cpp
