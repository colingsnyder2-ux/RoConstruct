// from server: 100% by auto
// roc 2010-06 00805d80  unit: CXTPPropExchangeArchive  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00805d80
//
// 00805d80  51                   push ecx
// 00805d81  8b442408             mov eax, dword ptr [esp + 8]
// 00805d85  56                   push esi
// 00805d86  57                   push edi
// 00805d87  8bf1                 mov esi, ecx
// 00805d89  85c0                 test eax, eax
// 00805d8b  7437                 je 0x805dc4
// 00805d8d  8b08                 mov ecx, dword ptr [eax]
// 00805d8f  53                   push ebx
// 00805d90  8d54240c             lea edx, [esp + 0xc]
// 00805d94  52                   push edx
// 00805d95  68ec06a600           push 0xa606ec
// 00805d9a  50                   push eax
// 00805d9b  8b01                 mov eax, dword ptr [ecx]
// 00805d9d  ffd0                 call eax
// 00805d9f  33db                 xor ebx, ebx
// 00805da1  8bf8                 mov edi, eax
// 00805da3  8b06                 mov eax, dword ptr [esi]
// 00805da5  85ff                 test edi, edi
// 00805da7  0f9cc3               setl bl
// 00805daa  4b                   dec ebx
// 00805dab  235c240c             and ebx, dword ptr [esp + 0xc]
// 00805daf  85c0                 test eax, eax
// 00805db1  7408                 je 0x805dbb
// 00805db3  8b08                 mov ecx, dword ptr [eax]
// 00805db5  8b5108               mov edx, dword ptr [ecx + 8]
// 00805db8  50                   push eax
// 00805db9  ffd2                 call edx
// 00805dbb  8b442414             mov eax, dword ptr [esp + 0x14]
// 00805dbf  891e                 mov dword ptr [esi], ebx
// 00805dc1  5b                   pop ebx
// 00805dc2  eb1d                 jmp 0x805de1
// 00805dc4  8b0e                 mov ecx, dword ptr [esi]
// 00805dc6  85c9                 test ecx, ecx
// 00805dc8  7412                 je 0x805ddc
// 00805dca  c70600000000         mov dword ptr [esi], 0
// 00805dd0  8b01                 mov eax, dword ptr [ecx]
// 00805dd2  51                   push ecx
// 00805dd3  8b4808               mov ecx, dword ptr [eax + 8]
// 00805dd6  ffd1                 call ecx
// 00805dd8  8b442410             mov eax, dword ptr [esp + 0x10]
// 00805ddc  bf02400080           mov edi, 0x80004002
// 00805de1  85c0                 test eax, eax
// 00805de3  7408                 je 0x805ded
// 00805de5  8b10                 mov edx, dword ptr [eax]
// 00805de7  50                   push eax
// 00805de8  8b4208               mov eax, dword ptr [edx + 8]
// 00805deb  ffd0                 call eax
// 00805ded  8bc7                 mov eax, edi
// 00805def  5f                   pop edi
// 00805df0  5e                   pop esi
// 00805df1  59                   pop ecx
// 00805df2  c20400               ret 4
// library xtp-13.2.1/Source\Common\XTPPropExchange.cpp (function ??$_QueryInterface@V?$_com_ptr_t@V?$_com_IIID@UIXMLDOMNode@XTPXML@@$1?_GUID_2933bf80_7b36_11d2_b20e_00c04f983e60@@3U__s_GUID@@B@@@@@?$_com_ptr_t@V?$_com_IIID@UIXMLDOMDocument@XTPXML@@$1?_GUID_2933bf81_7b36_11d2_b20e_00c04f983e60@@3U__s_GUID@@B@@@@AAEJV?$_com_ptr_t@V?$_com_IIID@UIXMLDOMNode@XTPXML@@$1?_GUID_2933bf80_7b36_11d2_b20e_00c04f983e60@@3U__s_GUID@@B@@@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPPropExchange.cpp
