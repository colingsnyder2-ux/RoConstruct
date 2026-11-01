// from server: 100% by auto
// roc 2007-03 00667fa0  unit: seg_00660000  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00667fa0
//
// 00667fa0  56                   push esi
// 00667fa1  8bf1                 mov esi, ecx
// 00667fa3  8b06                 mov eax, dword ptr [esi]
// 00667fa5  85c0                 test eax, eax
// 00667fa7  7408                 je 0x667fb1
// 00667fa9  8b08                 mov ecx, dword ptr [eax]
// 00667fab  8b5108               mov edx, dword ptr [ecx + 8]
// 00667fae  50                   push eax
// 00667faf  ffd2                 call edx
// 00667fb1  8bc6                 mov eax, esi
// 00667fb3  c70600000000         mov dword ptr [esi], 0
// 00667fb9  5e                   pop esi
// 00667fba  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPPropExchange.cpp (function ??I?$_com_ptr_t@V?$_com_IIID@UIXMLDOMDocument@XTPXML@@$1?_GUID_2933bf81_7b36_11d2_b20e_00c04f983e60@@3U__s_GUID@@B@@@@QAEPAPAUIXMLDOMDocument@XTPXML@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPPropExchange.cpp
