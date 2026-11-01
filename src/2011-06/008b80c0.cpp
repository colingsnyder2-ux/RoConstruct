// from server: 100% by auto
// roc 2011-06 008b80c0  unit: CXTPReportHyperlinks  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008b80c0
//
// 008b80c0  55                   push ebp
// 008b80c1  57                   push edi
// 008b80c2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 008b80c6  8be9                 mov ebp, ecx
// 008b80c8  3bfd                 cmp edi, ebp
// 008b80ca  7452                 je 0x8b811e
// 008b80cc  8b4500               mov eax, dword ptr [ebp]
// 008b80cf  8b9090000000         mov edx, dword ptr [eax + 0x90]
// 008b80d5  ffd2                 call edx
// 008b80d7  85ff                 test edi, edi
// 008b80d9  7443                 je 0x8b811e
// 008b80db  8b07                 mov eax, dword ptr [edi]
// 008b80dd  8b5058               mov edx, dword ptr [eax + 0x58]
// 008b80e0  53                   push ebx
// 008b80e1  8bcf                 mov ecx, edi
// 008b80e3  ffd2                 call edx
// 008b80e5  33db                 xor ebx, ebx
// 008b80e7  89442410             mov dword ptr [esp + 0x10], eax
// 008b80eb  85c0                 test eax, eax
// 008b80ed  7e2e                 jle 0x8b811d
// 008b80ef  56                   push esi
// 008b80f0  8b07                 mov eax, dword ptr [edi]
// 008b80f2  8b5060               mov edx, dword ptr [eax + 0x60]
// 008b80f5  53                   push ebx
// 008b80f6  8bcf                 mov ecx, edi
// 008b80f8  ffd2                 call edx
// 008b80fa  8bf0                 mov esi, eax
// 008b80fc  85f6                 test esi, esi
// 008b80fe  7415                 je 0x8b8115
// 008b8100  8d4604               lea eax, [esi + 4]
// 008b8103  50                   push eax
// 008b8104  ff154c03a400         call dword ptr [0xa4034c]
// 008b810a  8b5500               mov edx, dword ptr [ebp]
// 008b810d  8b4278               mov eax, dword ptr [edx + 0x78]
// 008b8110  56                   push esi
// 008b8111  8bcd                 mov ecx, ebp
// 008b8113  ffd0                 call eax
// 008b8115  43                   inc ebx
// 008b8116  3b5c2414             cmp ebx, dword ptr [esp + 0x14]
// 008b811a  7cd4                 jl 0x8b80f0
// 008b811c  5e                   pop esi
// 008b811d  5b                   pop ebx
// 008b811e  5f                   pop edi
// 008b811f  5d                   pop ebp
// 008b8120  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\ReportControl\XTPReportHyperlink.cpp (function ?CopyFrom@CXTPReportHyperlinks@@UAEXPAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/ReportControl/XTPReportHyperlink.cpp
