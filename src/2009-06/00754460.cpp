// from server: 100% by auto
// roc 2009-06 00754460  unit: CXTPReportSelectedRows  size: 100 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00754460
//
// 00754460  8b442404             mov eax, dword ptr [esp + 4]
// 00754464  85c0                 test eax, eax
// 00754466  7417                 je 0x75447f
// 00754468  6a0c                 push 0xc
// 0075446a  50                   push eax
// 0075446b  ff1558e18900         call dword ptr [0x89e158]
// 00754471  48                   dec eax
// 00754472  b907000000           mov ecx, 7
// 00754477  3bc8                 cmp ecx, eax
// 00754479  1bc0                 sbb eax, eax
// 0075447b  40                   inc eax
// 0075447c  c20400               ret 4
// 0075447f  53                   push ebx
// 00754480  8b1de8ec8900         mov ebx, dword ptr [0x89ece8]
// 00754486  56                   push esi
// 00754487  ffd3                 call ebx
// 00754489  50                   push eax
// 0075448a  ff1550ed8900         call dword ptr [0x89ed50]
// 00754490  8bf0                 mov esi, eax
// 00754492  85f6                 test esi, esi
// 00754494  7427                 je 0x7544bd
// 00754496  57                   push edi
// 00754497  6a0c                 push 0xc
// 00754499  56                   push esi
// 0075449a  ff1558e18900         call dword ptr [0x89e158]
// 007544a0  56                   push esi
// 007544a1  8bf8                 mov edi, eax
// 007544a3  ffd3                 call ebx
// 007544a5  50                   push eax
// 007544a6  ff1540ed8900         call dword ptr [0x89ed40]
// 007544ac  4f                   dec edi
// 007544ad  ba07000000           mov edx, 7
// 007544b2  3bd7                 cmp edx, edi
// 007544b4  5f                   pop edi
// 007544b5  1bc0                 sbb eax, eax
// 007544b7  5e                   pop esi
// 007544b8  40                   inc eax
// 007544b9  5b                   pop ebx
// 007544ba  c20400               ret 4
// 007544bd  5e                   pop esi
// 007544be  33c0                 xor eax, eax
// 007544c0  5b                   pop ebx
// 007544c1  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPColorManager.cpp (function ?IsLowResolution@CXTPColorManager@@QAEHPAUHDC__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPColorManager.cpp
