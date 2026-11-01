// from server: 100% by auto
// roc 2009-06 00776f90  unit: CXTPPropExchangeArchive  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00776f90
//
// 00776f90  56                   push esi
// 00776f91  8bf1                 mov esi, ecx
// 00776f93  8b06                 mov eax, dword ptr [esi]
// 00776f95  85c0                 test eax, eax
// 00776f97  7408                 je 0x776fa1
// 00776f99  8b08                 mov ecx, dword ptr [eax]
// 00776f9b  8b5108               mov edx, dword ptr [ecx + 8]
// 00776f9e  50                   push eax
// 00776f9f  ffd2                 call edx
// 00776fa1  8bc6                 mov eax, esi
// 00776fa3  c70600000000         mov dword ptr [esi], 0
// 00776fa9  5e                   pop esi
// 00776faa  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPPropExchange.cpp (function ??I?$_com_ptr_t@V?$_com_IIID@UIXMLDOMDocument@XTPXML@@$1?_GUID_2933bf81_7b36_11d2_b20e_00c04f983e60@@3U__s_GUID@@B@@@@QAEPAPAUIXMLDOMDocument@XTPXML@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPPropExchange.cpp
