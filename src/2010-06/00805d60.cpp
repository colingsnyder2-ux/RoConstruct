// from server: 100% by auto
// roc 2010-06 00805d60  unit: CXTPPropExchangeArchive  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00805d60
//
// 00805d60  56                   push esi
// 00805d61  8bf1                 mov esi, ecx
// 00805d63  8b06                 mov eax, dword ptr [esi]
// 00805d65  85c0                 test eax, eax
// 00805d67  7408                 je 0x805d71
// 00805d69  8b08                 mov ecx, dword ptr [eax]
// 00805d6b  8b5108               mov edx, dword ptr [ecx + 8]
// 00805d6e  50                   push eax
// 00805d6f  ffd2                 call edx
// 00805d71  8bc6                 mov eax, esi
// 00805d73  c70600000000         mov dword ptr [esi], 0
// 00805d79  5e                   pop esi
// 00805d7a  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPPropExchange.cpp (function ??I?$_com_ptr_t@V?$_com_IIID@UIXMLDOMDocument@XTPXML@@$1?_GUID_2933bf81_7b36_11d2_b20e_00c04f983e60@@3U__s_GUID@@B@@@@QAEPAPAUIXMLDOMDocument@XTPXML@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPPropExchange.cpp
