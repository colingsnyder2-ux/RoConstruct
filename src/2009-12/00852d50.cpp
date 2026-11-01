// from server: 100% by auto
// roc 2009-12 00852d50  unit: CXTPPropExchangeXMLNode  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00852d50
//
// 00852d50  51                   push ecx
// 00852d51  8b442408             mov eax, dword ptr [esp + 8]
// 00852d55  56                   push esi
// 00852d56  57                   push edi
// 00852d57  8bf1                 mov esi, ecx
// 00852d59  85c0                 test eax, eax
// 00852d5b  7437                 je 0x852d94
// 00852d5d  8b08                 mov ecx, dword ptr [eax]
// 00852d5f  53                   push ebx
// 00852d60  8d54240c             lea edx, [esp + 0xc]
// 00852d64  52                   push edx
// 00852d65  683cc49f00           push 0x9fc43c
// 00852d6a  50                   push eax
// 00852d6b  8b01                 mov eax, dword ptr [ecx]
// 00852d6d  ffd0                 call eax
// 00852d6f  33db                 xor ebx, ebx
// 00852d71  8bf8                 mov edi, eax
// 00852d73  8b06                 mov eax, dword ptr [esi]
// 00852d75  85ff                 test edi, edi
// 00852d77  0f9cc3               setl bl
// 00852d7a  4b                   dec ebx
// 00852d7b  235c240c             and ebx, dword ptr [esp + 0xc]
// 00852d7f  85c0                 test eax, eax
// 00852d81  7408                 je 0x852d8b
// 00852d83  8b08                 mov ecx, dword ptr [eax]
// 00852d85  8b5108               mov edx, dword ptr [ecx + 8]
// 00852d88  50                   push eax
// 00852d89  ffd2                 call edx
// 00852d8b  8b442414             mov eax, dword ptr [esp + 0x14]
// 00852d8f  891e                 mov dword ptr [esi], ebx
// 00852d91  5b                   pop ebx
// 00852d92  eb1d                 jmp 0x852db1
// 00852d94  8b0e                 mov ecx, dword ptr [esi]
// 00852d96  85c9                 test ecx, ecx
// 00852d98  7412                 je 0x852dac
// 00852d9a  c70600000000         mov dword ptr [esi], 0
// 00852da0  8b01                 mov eax, dword ptr [ecx]
// 00852da2  51                   push ecx
// 00852da3  8b4808               mov ecx, dword ptr [eax + 8]
// 00852da6  ffd1                 call ecx
// 00852da8  8b442410             mov eax, dword ptr [esp + 0x10]
// 00852dac  bf02400080           mov edi, 0x80004002
// 00852db1  85c0                 test eax, eax
// 00852db3  7408                 je 0x852dbd
// 00852db5  8b10                 mov edx, dword ptr [eax]
// 00852db7  50                   push eax
// 00852db8  8b4208               mov eax, dword ptr [edx + 8]
// 00852dbb  ffd0                 call eax
// 00852dbd  8bc7                 mov eax, edi
// 00852dbf  5f                   pop edi
// 00852dc0  5e                   pop esi
// 00852dc1  59                   pop ecx
// 00852dc2  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPPropExchange.cpp (function ??$_QueryInterface@V?$_com_ptr_t@V?$_com_IIID@UIXMLDOMDocument@XTPXML@@$1?_GUID_2933bf81_7b36_11d2_b20e_00c04f983e60@@3U__s_GUID@@B@@@@@?$_com_ptr_t@V?$_com_IIID@UIXMLDOMNode@XTPXML@@$1?_GUID_2933bf80_7b36_11d2_b20e_00c04f983e60@@3U__s_GUID@@B@@@@AAEJV?$_com_ptr_t@V?$_com_IIID@UIXMLDOMDocument@XTPXML@@$1?_GUID_2933bf81_7b36_11d2_b20e_00c04f983e60@@3U__s_GUID@@B@@@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPPropExchange.cpp
