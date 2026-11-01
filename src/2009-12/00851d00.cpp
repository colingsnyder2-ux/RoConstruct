// from server: 100% by auto
// roc 2009-12 00851d00  unit: CXTPPropExchangeArchive  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00851d00
//
// 00851d00  56                   push esi
// 00851d01  8bf1                 mov esi, ecx
// 00851d03  8b06                 mov eax, dword ptr [esi]
// 00851d05  85c0                 test eax, eax
// 00851d07  7408                 je 0x851d11
// 00851d09  8b08                 mov ecx, dword ptr [eax]
// 00851d0b  8b5108               mov edx, dword ptr [ecx + 8]
// 00851d0e  50                   push eax
// 00851d0f  ffd2                 call edx
// 00851d11  8bc6                 mov eax, esi
// 00851d13  c70600000000         mov dword ptr [esi], 0
// 00851d19  5e                   pop esi
// 00851d1a  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPPropExchange.cpp (function ??I?$_com_ptr_t@V?$_com_IIID@UIXMLDOMDocument@XTPXML@@$1?_GUID_2933bf81_7b36_11d2_b20e_00c04f983e60@@3U__s_GUID@@B@@@@QAEPAPAUIXMLDOMDocument@XTPXML@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPPropExchange.cpp
