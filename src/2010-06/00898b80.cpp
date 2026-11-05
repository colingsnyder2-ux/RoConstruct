// from server: 100% by auto
// roc 2010-06 00898b80  unit: CXTCaptionTheme  size: 161 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00898b80
//
// 00898b80  83ec10               sub esp, 0x10
// 00898b83  57                   push edi
// 00898b84  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00898b88  8b87cc000000         mov eax, dword ptr [edi + 0xcc]
// 00898b8e  8944241c             mov dword ptr [esp + 0x1c], eax
// 00898b92  85c0                 test eax, eax
// 00898b94  0f8480000000         je 0x898c1a
// 00898b9a  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00898b9e  8b5104               mov edx, dword ptr [ecx + 4]
// 00898ba1  8b01                 mov eax, dword ptr [ecx]
// 00898ba3  89542408             mov dword ptr [esp + 8], edx
// 00898ba7  8b510c               mov edx, dword ptr [ecx + 0xc]
// 00898baa  89442404             mov dword ptr [esp + 4], eax
// 00898bae  8b4108               mov eax, dword ptr [ecx + 8]
// 00898bb1  53                   push ebx
// 00898bb2  89542414             mov dword ptr [esp + 0x14], edx
// 00898bb6  8b576c               mov edx, dword ptr [edi + 0x6c]
// 00898bb9  55                   push ebp
// 00898bba  8baf90000000         mov ebp, dword ptr [edi + 0x90]
// 00898bc0  2bc2                 sub eax, edx
// 00898bc2  2bc5                 sub eax, ebp
// 00898bc4  83e802               sub eax, 2
// 00898bc7  56                   push esi
// 00898bc8  8bf0                 mov esi, eax
// 00898bca  3bf2                 cmp esi, edx
// 00898bcc  7d02                 jge 0x898bd0
// 00898bce  8bf2                 mov esi, edx
// 00898bd0  8b410c               mov eax, dword ptr [ecx + 0xc]
// 00898bd3  2b4104               sub eax, dword ptr [ecx + 4]
// 00898bd6  8b9f94000000         mov ebx, dword ptr [edi + 0x94]
// 00898bdc  8b4908               mov ecx, dword ptr [ecx + 8]
// 00898bdf  2b4f6c               sub ecx, dword ptr [edi + 0x6c]
// 00898be2  2bc3                 sub eax, ebx
// 00898be4  99                   cdq 
// 00898be5  2bc2                 sub eax, edx
// 00898be7  d1f8                 sar eax, 1
// 00898be9  8d142e               lea edx, [esi + ebp]
// 00898bec  03d8                 add ebx, eax
// 00898bee  3bd1                 cmp edx, ecx
// 00898bf0  7d25                 jge 0x898c17
// 00898bf2  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00898bf6  85c9                 test ecx, ecx
// 00898bf8  7403                 je 0x898bfd
// 00898bfa  8b4904               mov ecx, dword ptr [ecx + 4]
// 00898bfd  6a03                 push 3
// 00898bff  6a00                 push 0
// 00898c01  6a00                 push 0
// 00898c03  2bd8                 sub ebx, eax
// 00898c05  53                   push ebx
// 00898c06  2bd6                 sub edx, esi
// 00898c08  52                   push edx
// 00898c09  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 00898c0d  52                   push edx
// 00898c0e  50                   push eax
// 00898c0f  56                   push esi
// 00898c10  51                   push ecx
// 00898c11  ff15ccb99e00         call dword ptr [0x9eb9cc]
// 00898c17  5e                   pop esi
// 00898c18  5d                   pop ebp
// 00898c19  5b                   pop ebx
// 00898c1a  5f                   pop edi
// 00898c1b  83c410               add esp, 0x10
// 00898c1e  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTCaptionTheme.cpp (function ?DrawCaptionIcon@CXTCaptionTheme@@UAEXPAVCDC@@PAVCXTCaption@@AAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionTheme.cpp
