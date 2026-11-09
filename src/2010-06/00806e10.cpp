// from server: 100% by auto
// roc 2010-06 00806e10  unit: CXTPPropExchangeXMLNode  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00806e10
//
// 00806e10  51                   push ecx
// 00806e11  8b442408             mov eax, dword ptr [esp + 8]
// 00806e15  56                   push esi
// 00806e16  57                   push edi
// 00806e17  8bf1                 mov esi, ecx
// 00806e19  85c0                 test eax, eax
// 00806e1b  7437                 je 0x806e54
// 00806e1d  8b08                 mov ecx, dword ptr [eax]
// 00806e1f  53                   push ebx
// 00806e20  8d54240c             lea edx, [esp + 0xc]
// 00806e24  52                   push edx
// 00806e25  68fc06a600           push 0xa606fc
// 00806e2a  50                   push eax
// 00806e2b  8b01                 mov eax, dword ptr [ecx]
// 00806e2d  ffd0                 call eax
// 00806e2f  33db                 xor ebx, ebx
// 00806e31  8bf8                 mov edi, eax
// 00806e33  8b06                 mov eax, dword ptr [esi]
// 00806e35  85ff                 test edi, edi
// 00806e37  0f9cc3               setl bl
// 00806e3a  4b                   dec ebx
// 00806e3b  235c240c             and ebx, dword ptr [esp + 0xc]
// 00806e3f  85c0                 test eax, eax
// 00806e41  7408                 je 0x806e4b
// 00806e43  8b08                 mov ecx, dword ptr [eax]
// 00806e45  8b5108               mov edx, dword ptr [ecx + 8]
// 00806e48  50                   push eax
// 00806e49  ffd2                 call edx
// 00806e4b  8b442414             mov eax, dword ptr [esp + 0x14]
// 00806e4f  891e                 mov dword ptr [esi], ebx
// 00806e51  5b                   pop ebx
// 00806e52  eb1d                 jmp 0x806e71
// 00806e54  8b0e                 mov ecx, dword ptr [esi]
// 00806e56  85c9                 test ecx, ecx
// 00806e58  7412                 je 0x806e6c
// 00806e5a  c70600000000         mov dword ptr [esi], 0
// 00806e60  8b01                 mov eax, dword ptr [ecx]
// 00806e62  51                   push ecx
// 00806e63  8b4808               mov ecx, dword ptr [eax + 8]
// 00806e66  ffd1                 call ecx
// 00806e68  8b442410             mov eax, dword ptr [esp + 0x10]
// 00806e6c  bf02400080           mov edi, 0x80004002
// 00806e71  85c0                 test eax, eax
// 00806e73  7408                 je 0x806e7d
// 00806e75  8b10                 mov edx, dword ptr [eax]
// 00806e77  50                   push eax
// 00806e78  8b4208               mov eax, dword ptr [edx + 8]
// 00806e7b  ffd0                 call eax
// 00806e7d  8bc7                 mov eax, edi
// 00806e7f  5f                   pop edi
// 00806e80  5e                   pop esi
// 00806e81  59                   pop ecx
// 00806e82  c20400               ret 4
// library xtp-13.2.1/Source\Common\XTPPropExchange.cpp (function ??$_QueryInterface@V?$_com_ptr_t@V?$_com_IIID@UIXMLDOMDocument@XTPXML@@$1?_GUID_2933bf81_7b36_11d2_b20e_00c04f983e60@@3U__s_GUID@@B@@@@@?$_com_ptr_t@V?$_com_IIID@UIXMLDOMNode@XTPXML@@$1?_GUID_2933bf80_7b36_11d2_b20e_00c04f983e60@@3U__s_GUID@@B@@@@AAEJV?$_com_ptr_t@V?$_com_IIID@UIXMLDOMDocument@XTPXML@@$1?_GUID_2933bf81_7b36_11d2_b20e_00c04f983e60@@3U__s_GUID@@B@@@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPPropExchange.cpp
