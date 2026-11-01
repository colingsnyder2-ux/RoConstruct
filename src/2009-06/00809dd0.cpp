// from server: 100% by auto
// roc 2009-06 00809dd0  unit: CXTCaptionTheme  size: 161 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00809dd0
//
// 00809dd0  83ec10               sub esp, 0x10
// 00809dd3  57                   push edi
// 00809dd4  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00809dd8  8b87cc000000         mov eax, dword ptr [edi + 0xcc]
// 00809dde  8944241c             mov dword ptr [esp + 0x1c], eax
// 00809de2  85c0                 test eax, eax
// 00809de4  0f8480000000         je 0x809e6a
// 00809dea  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00809dee  8b5104               mov edx, dword ptr [ecx + 4]
// 00809df1  8b01                 mov eax, dword ptr [ecx]
// 00809df3  89542408             mov dword ptr [esp + 8], edx
// 00809df7  8b510c               mov edx, dword ptr [ecx + 0xc]
// 00809dfa  89442404             mov dword ptr [esp + 4], eax
// 00809dfe  8b4108               mov eax, dword ptr [ecx + 8]
// 00809e01  53                   push ebx
// 00809e02  89542414             mov dword ptr [esp + 0x14], edx
// 00809e06  8b576c               mov edx, dword ptr [edi + 0x6c]
// 00809e09  55                   push ebp
// 00809e0a  8baf90000000         mov ebp, dword ptr [edi + 0x90]
// 00809e10  2bc2                 sub eax, edx
// 00809e12  2bc5                 sub eax, ebp
// 00809e14  83e802               sub eax, 2
// 00809e17  56                   push esi
// 00809e18  8bf0                 mov esi, eax
// 00809e1a  3bf2                 cmp esi, edx
// 00809e1c  7d02                 jge 0x809e20
// 00809e1e  8bf2                 mov esi, edx
// 00809e20  8b410c               mov eax, dword ptr [ecx + 0xc]
// 00809e23  2b4104               sub eax, dword ptr [ecx + 4]
// 00809e26  8b9f94000000         mov ebx, dword ptr [edi + 0x94]
// 00809e2c  8b4908               mov ecx, dword ptr [ecx + 8]
// 00809e2f  2b4f6c               sub ecx, dword ptr [edi + 0x6c]
// 00809e32  2bc3                 sub eax, ebx
// 00809e34  99                   cdq 
// 00809e35  2bc2                 sub eax, edx
// 00809e37  d1f8                 sar eax, 1
// 00809e39  8d142e               lea edx, [esi + ebp]
// 00809e3c  03d8                 add ebx, eax
// 00809e3e  3bd1                 cmp edx, ecx
// 00809e40  7d25                 jge 0x809e67
// 00809e42  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00809e46  85c9                 test ecx, ecx
// 00809e48  7403                 je 0x809e4d
// 00809e4a  8b4904               mov ecx, dword ptr [ecx + 4]
// 00809e4d  6a03                 push 3
// 00809e4f  6a00                 push 0
// 00809e51  6a00                 push 0
// 00809e53  2bd8                 sub ebx, eax
// 00809e55  53                   push ebx
// 00809e56  2bd6                 sub edx, esi
// 00809e58  52                   push edx
// 00809e59  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 00809e5d  52                   push edx
// 00809e5e  50                   push eax
// 00809e5f  56                   push esi
// 00809e60  51                   push ecx
// 00809e61  ff1528ef8900         call dword ptr [0x89ef28]
// 00809e67  5e                   pop esi
// 00809e68  5d                   pop ebp
// 00809e69  5b                   pop ebx
// 00809e6a  5f                   pop edi
// 00809e6b  83c410               add esp, 0x10
// 00809e6e  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTCaptionTheme.cpp (function ?DrawCaptionIcon@CXTCaptionTheme@@UAEXPAVCDC@@PAVCXTCaption@@AAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionTheme.cpp
