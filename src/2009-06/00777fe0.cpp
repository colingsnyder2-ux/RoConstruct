// from server: 100% by auto
// roc 2009-06 00777fe0  unit: CXTPPropExchangeXMLNode  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00777fe0
//
// 00777fe0  51                   push ecx
// 00777fe1  8b442408             mov eax, dword ptr [esp + 8]
// 00777fe5  56                   push esi
// 00777fe6  57                   push edi
// 00777fe7  8bf1                 mov esi, ecx
// 00777fe9  85c0                 test eax, eax
// 00777feb  7437                 je 0x778024
// 00777fed  8b08                 mov ecx, dword ptr [eax]
// 00777fef  53                   push ebx
// 00777ff0  8d54240c             lea edx, [esp + 0xc]
// 00777ff4  52                   push edx
// 00777ff5  6894bf8f00           push 0x8fbf94
// 00777ffa  50                   push eax
// 00777ffb  8b01                 mov eax, dword ptr [ecx]
// 00777ffd  ffd0                 call eax
// 00777fff  33db                 xor ebx, ebx
// 00778001  8bf8                 mov edi, eax
// 00778003  8b06                 mov eax, dword ptr [esi]
// 00778005  85ff                 test edi, edi
// 00778007  0f9cc3               setl bl
// 0077800a  4b                   dec ebx
// 0077800b  235c240c             and ebx, dword ptr [esp + 0xc]
// 0077800f  85c0                 test eax, eax
// 00778011  7408                 je 0x77801b
// 00778013  8b08                 mov ecx, dword ptr [eax]
// 00778015  8b5108               mov edx, dword ptr [ecx + 8]
// 00778018  50                   push eax
// 00778019  ffd2                 call edx
// 0077801b  8b442414             mov eax, dword ptr [esp + 0x14]
// 0077801f  891e                 mov dword ptr [esi], ebx
// 00778021  5b                   pop ebx
// 00778022  eb1d                 jmp 0x778041
// 00778024  8b0e                 mov ecx, dword ptr [esi]
// 00778026  85c9                 test ecx, ecx
// 00778028  7412                 je 0x77803c
// 0077802a  c70600000000         mov dword ptr [esi], 0
// 00778030  8b01                 mov eax, dword ptr [ecx]
// 00778032  51                   push ecx
// 00778033  8b4808               mov ecx, dword ptr [eax + 8]
// 00778036  ffd1                 call ecx
// 00778038  8b442410             mov eax, dword ptr [esp + 0x10]
// 0077803c  bf02400080           mov edi, 0x80004002
// 00778041  85c0                 test eax, eax
// 00778043  7408                 je 0x77804d
// 00778045  8b10                 mov edx, dword ptr [eax]
// 00778047  50                   push eax
// 00778048  8b4208               mov eax, dword ptr [edx + 8]
// 0077804b  ffd0                 call eax
// 0077804d  8bc7                 mov eax, edi
// 0077804f  5f                   pop edi
// 00778050  5e                   pop esi
// 00778051  59                   pop ecx
// 00778052  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPPropExchange.cpp (function ??$_QueryInterface@V?$_com_ptr_t@V?$_com_IIID@UIXMLDOMDocument@XTPXML@@$1?_GUID_2933bf81_7b36_11d2_b20e_00c04f983e60@@3U__s_GUID@@B@@@@@?$_com_ptr_t@V?$_com_IIID@UIXMLDOMNode@XTPXML@@$1?_GUID_2933bf80_7b36_11d2_b20e_00c04f983e60@@3U__s_GUID@@B@@@@AAEJV?$_com_ptr_t@V?$_com_IIID@UIXMLDOMDocument@XTPXML@@$1?_GUID_2933bf81_7b36_11d2_b20e_00c04f983e60@@3U__s_GUID@@B@@@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPPropExchange.cpp
