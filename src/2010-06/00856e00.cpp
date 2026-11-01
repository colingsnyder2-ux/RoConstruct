// from server: 100% by auto
// roc 2010-06 00856e00  unit: CXTPReportHyperlinks  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00856e00
//
// 00856e00  55                   push ebp
// 00856e01  57                   push edi
// 00856e02  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00856e06  8be9                 mov ebp, ecx
// 00856e08  3bfd                 cmp edi, ebp
// 00856e0a  7452                 je 0x856e5e
// 00856e0c  8b4500               mov eax, dword ptr [ebp]
// 00856e0f  8b9090000000         mov edx, dword ptr [eax + 0x90]
// 00856e15  ffd2                 call edx
// 00856e17  85ff                 test edi, edi
// 00856e19  7443                 je 0x856e5e
// 00856e1b  8b07                 mov eax, dword ptr [edi]
// 00856e1d  8b5058               mov edx, dword ptr [eax + 0x58]
// 00856e20  53                   push ebx
// 00856e21  8bcf                 mov ecx, edi
// 00856e23  ffd2                 call edx
// 00856e25  33db                 xor ebx, ebx
// 00856e27  89442410             mov dword ptr [esp + 0x10], eax
// 00856e2b  85c0                 test eax, eax
// 00856e2d  7e2e                 jle 0x856e5d
// 00856e2f  56                   push esi
// 00856e30  8b07                 mov eax, dword ptr [edi]
// 00856e32  8b5060               mov edx, dword ptr [eax + 0x60]
// 00856e35  53                   push ebx
// 00856e36  8bcf                 mov ecx, edi
// 00856e38  ffd2                 call edx
// 00856e3a  8bf0                 mov esi, eax
// 00856e3c  85f6                 test esi, esi
// 00856e3e  7415                 je 0x856e55
// 00856e40  8d4604               lea eax, [esi + 4]
// 00856e43  50                   push eax
// 00856e44  ff1580a39e00         call dword ptr [0x9ea380]
// 00856e4a  8b5500               mov edx, dword ptr [ebp]
// 00856e4d  8b4278               mov eax, dword ptr [edx + 0x78]
// 00856e50  56                   push esi
// 00856e51  8bcd                 mov ecx, ebp
// 00856e53  ffd0                 call eax
// 00856e55  43                   inc ebx
// 00856e56  3b5c2414             cmp ebx, dword ptr [esp + 0x14]
// 00856e5a  7cd4                 jl 0x856e30
// 00856e5c  5e                   pop esi
// 00856e5d  5b                   pop ebx
// 00856e5e  5f                   pop edi
// 00856e5f  5d                   pop ebp
// 00856e60  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\ReportControl\XTPReportHyperlink.cpp (function ?CopyFrom@CXTPReportHyperlinks@@UAEXPAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/ReportControl/XTPReportHyperlink.cpp
