// from server: 100% by auto
// roc 2011-06 008f16d0  unit: CXTCaptionTheme  size: 161 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008f16d0
//
// 008f16d0  83ec10               sub esp, 0x10
// 008f16d3  57                   push edi
// 008f16d4  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 008f16d8  8b87cc000000         mov eax, dword ptr [edi + 0xcc]
// 008f16de  8944241c             mov dword ptr [esp + 0x1c], eax
// 008f16e2  85c0                 test eax, eax
// 008f16e4  0f8480000000         je 0x8f176a
// 008f16ea  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008f16ee  8b5104               mov edx, dword ptr [ecx + 4]
// 008f16f1  8b01                 mov eax, dword ptr [ecx]
// 008f16f3  89542408             mov dword ptr [esp + 8], edx
// 008f16f7  8b510c               mov edx, dword ptr [ecx + 0xc]
// 008f16fa  89442404             mov dword ptr [esp + 4], eax
// 008f16fe  8b4108               mov eax, dword ptr [ecx + 8]
// 008f1701  53                   push ebx
// 008f1702  89542414             mov dword ptr [esp + 0x14], edx
// 008f1706  8b576c               mov edx, dword ptr [edi + 0x6c]
// 008f1709  55                   push ebp
// 008f170a  8baf90000000         mov ebp, dword ptr [edi + 0x90]
// 008f1710  2bc2                 sub eax, edx
// 008f1712  2bc5                 sub eax, ebp
// 008f1714  83e802               sub eax, 2
// 008f1717  56                   push esi
// 008f1718  8bf0                 mov esi, eax
// 008f171a  3bf2                 cmp esi, edx
// 008f171c  7d02                 jge 0x8f1720
// 008f171e  8bf2                 mov esi, edx
// 008f1720  8b410c               mov eax, dword ptr [ecx + 0xc]
// 008f1723  2b4104               sub eax, dword ptr [ecx + 4]
// 008f1726  8b9f94000000         mov ebx, dword ptr [edi + 0x94]
// 008f172c  8b4908               mov ecx, dword ptr [ecx + 8]
// 008f172f  2b4f6c               sub ecx, dword ptr [edi + 0x6c]
// 008f1732  2bc3                 sub eax, ebx
// 008f1734  99                   cdq 
// 008f1735  2bc2                 sub eax, edx
// 008f1737  d1f8                 sar eax, 1
// 008f1739  8d142e               lea edx, [esi + ebp]
// 008f173c  03d8                 add ebx, eax
// 008f173e  3bd1                 cmp edx, ecx
// 008f1740  7d25                 jge 0x8f1767
// 008f1742  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 008f1746  85c9                 test ecx, ecx
// 008f1748  7403                 je 0x8f174d
// 008f174a  8b4904               mov ecx, dword ptr [ecx + 4]
// 008f174d  6a03                 push 3
// 008f174f  6a00                 push 0
// 008f1751  6a00                 push 0
// 008f1753  2bd8                 sub ebx, eax
// 008f1755  53                   push ebx
// 008f1756  2bd6                 sub edx, esi
// 008f1758  52                   push edx
// 008f1759  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 008f175d  52                   push edx
// 008f175e  50                   push eax
// 008f175f  56                   push esi
// 008f1760  51                   push ecx
// 008f1761  ff15bc1aa400         call dword ptr [0xa41abc]
// 008f1767  5e                   pop esi
// 008f1768  5d                   pop ebp
// 008f1769  5b                   pop ebx
// 008f176a  5f                   pop edi
// 008f176b  83c410               add esp, 0x10
// 008f176e  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTCaptionTheme.cpp (function ?DrawCaptionIcon@CXTCaptionTheme@@UAEXPAVCDC@@PAVCXTCaption@@AAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionTheme.cpp
