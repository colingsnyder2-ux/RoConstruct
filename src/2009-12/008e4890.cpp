// from server: 100% by auto
// roc 2009-12 008e4890  unit: CXTCaptionTheme  size: 161 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e4890
//
// 008e4890  83ec10               sub esp, 0x10
// 008e4893  57                   push edi
// 008e4894  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 008e4898  8b87cc000000         mov eax, dword ptr [edi + 0xcc]
// 008e489e  8944241c             mov dword ptr [esp + 0x1c], eax
// 008e48a2  85c0                 test eax, eax
// 008e48a4  0f8480000000         je 0x8e492a
// 008e48aa  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008e48ae  8b5104               mov edx, dword ptr [ecx + 4]
// 008e48b1  8b01                 mov eax, dword ptr [ecx]
// 008e48b3  89542408             mov dword ptr [esp + 8], edx
// 008e48b7  8b510c               mov edx, dword ptr [ecx + 0xc]
// 008e48ba  89442404             mov dword ptr [esp + 4], eax
// 008e48be  8b4108               mov eax, dword ptr [ecx + 8]
// 008e48c1  53                   push ebx
// 008e48c2  89542414             mov dword ptr [esp + 0x14], edx
// 008e48c6  8b576c               mov edx, dword ptr [edi + 0x6c]
// 008e48c9  55                   push ebp
// 008e48ca  8baf90000000         mov ebp, dword ptr [edi + 0x90]
// 008e48d0  2bc2                 sub eax, edx
// 008e48d2  2bc5                 sub eax, ebp
// 008e48d4  83e802               sub eax, 2
// 008e48d7  56                   push esi
// 008e48d8  8bf0                 mov esi, eax
// 008e48da  3bf2                 cmp esi, edx
// 008e48dc  7d02                 jge 0x8e48e0
// 008e48de  8bf2                 mov esi, edx
// 008e48e0  8b410c               mov eax, dword ptr [ecx + 0xc]
// 008e48e3  2b4104               sub eax, dword ptr [ecx + 4]
// 008e48e6  8b9f94000000         mov ebx, dword ptr [edi + 0x94]
// 008e48ec  8b4908               mov ecx, dword ptr [ecx + 8]
// 008e48ef  2b4f6c               sub ecx, dword ptr [edi + 0x6c]
// 008e48f2  2bc3                 sub eax, ebx
// 008e48f4  99                   cdq 
// 008e48f5  2bc2                 sub eax, edx
// 008e48f7  d1f8                 sar eax, 1
// 008e48f9  8d142e               lea edx, [esi + ebp]
// 008e48fc  03d8                 add ebx, eax
// 008e48fe  3bd1                 cmp edx, ecx
// 008e4900  7d25                 jge 0x8e4927
// 008e4902  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 008e4906  85c9                 test ecx, ecx
// 008e4908  7403                 je 0x8e490d
// 008e490a  8b4904               mov ecx, dword ptr [ecx + 4]
// 008e490d  6a03                 push 3
// 008e490f  6a00                 push 0
// 008e4911  6a00                 push 0
// 008e4913  2bd8                 sub ebx, eax
// 008e4915  53                   push ebx
// 008e4916  2bd6                 sub edx, esi
// 008e4918  52                   push edx
// 008e4919  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 008e491d  52                   push edx
// 008e491e  50                   push eax
// 008e491f  56                   push esi
// 008e4920  51                   push ecx
// 008e4921  ff1514cb9800         call dword ptr [0x98cb14]
// 008e4927  5e                   pop esi
// 008e4928  5d                   pop ebp
// 008e4929  5b                   pop ebx
// 008e492a  5f                   pop edi
// 008e492b  83c410               add esp, 0x10
// 008e492e  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTCaptionTheme.cpp (function ?DrawCaptionIcon@CXTCaptionTheme@@UAEXPAVCDC@@PAVCXTCaption@@AAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionTheme.cpp
