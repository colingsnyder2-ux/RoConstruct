// from server: 100% by auto
// roc 2009-12 00851d20  unit: CXTPPropExchangeArchive  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00851d20
//
// 00851d20  51                   push ecx
// 00851d21  8b442408             mov eax, dword ptr [esp + 8]
// 00851d25  56                   push esi
// 00851d26  57                   push edi
// 00851d27  8bf1                 mov esi, ecx
// 00851d29  85c0                 test eax, eax
// 00851d2b  7437                 je 0x851d64
// 00851d2d  8b08                 mov ecx, dword ptr [eax]
// 00851d2f  53                   push ebx
// 00851d30  8d54240c             lea edx, [esp + 0xc]
// 00851d34  52                   push edx
// 00851d35  682cc49f00           push 0x9fc42c
// 00851d3a  50                   push eax
// 00851d3b  8b01                 mov eax, dword ptr [ecx]
// 00851d3d  ffd0                 call eax
// 00851d3f  33db                 xor ebx, ebx
// 00851d41  8bf8                 mov edi, eax
// 00851d43  8b06                 mov eax, dword ptr [esi]
// 00851d45  85ff                 test edi, edi
// 00851d47  0f9cc3               setl bl
// 00851d4a  4b                   dec ebx
// 00851d4b  235c240c             and ebx, dword ptr [esp + 0xc]
// 00851d4f  85c0                 test eax, eax
// 00851d51  7408                 je 0x851d5b
// 00851d53  8b08                 mov ecx, dword ptr [eax]
// 00851d55  8b5108               mov edx, dword ptr [ecx + 8]
// 00851d58  50                   push eax
// 00851d59  ffd2                 call edx
// 00851d5b  8b442414             mov eax, dword ptr [esp + 0x14]
// 00851d5f  891e                 mov dword ptr [esi], ebx
// 00851d61  5b                   pop ebx
// 00851d62  eb1d                 jmp 0x851d81
// 00851d64  8b0e                 mov ecx, dword ptr [esi]
// 00851d66  85c9                 test ecx, ecx
// 00851d68  7412                 je 0x851d7c
// 00851d6a  c70600000000         mov dword ptr [esi], 0
// 00851d70  8b01                 mov eax, dword ptr [ecx]
// 00851d72  51                   push ecx
// 00851d73  8b4808               mov ecx, dword ptr [eax + 8]
// 00851d76  ffd1                 call ecx
// 00851d78  8b442410             mov eax, dword ptr [esp + 0x10]
// 00851d7c  bf02400080           mov edi, 0x80004002
// 00851d81  85c0                 test eax, eax
// 00851d83  7408                 je 0x851d8d
// 00851d85  8b10                 mov edx, dword ptr [eax]
// 00851d87  50                   push eax
// 00851d88  8b4208               mov eax, dword ptr [edx + 8]
// 00851d8b  ffd0                 call eax
// 00851d8d  8bc7                 mov eax, edi
// 00851d8f  5f                   pop edi
// 00851d90  5e                   pop esi
// 00851d91  59                   pop ecx
// 00851d92  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPPropExchange.cpp (function ??$_QueryInterface@V?$_com_ptr_t@V?$_com_IIID@UIXMLDOMNode@XTPXML@@$1?_GUID_2933bf80_7b36_11d2_b20e_00c04f983e60@@3U__s_GUID@@B@@@@@?$_com_ptr_t@V?$_com_IIID@UIXMLDOMDocument@XTPXML@@$1?_GUID_2933bf81_7b36_11d2_b20e_00c04f983e60@@3U__s_GUID@@B@@@@AAEJV?$_com_ptr_t@V?$_com_IIID@UIXMLDOMNode@XTPXML@@$1?_GUID_2933bf80_7b36_11d2_b20e_00c04f983e60@@3U__s_GUID@@B@@@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPPropExchange.cpp
