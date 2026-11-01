// from server: 100% by auto
// roc 2009-06 00777f60  unit: CXTPPropExchangeXMLNode  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00777f60
//
// 00777f60  8b442404             mov eax, dword ptr [esp + 4]
// 00777f64  8b00                 mov eax, dword ptr [eax]
// 00777f66  56                   push esi
// 00777f67  8bf1                 mov esi, ecx
// 00777f69  57                   push edi
// 00777f6a  8b3e                 mov edi, dword ptr [esi]
// 00777f6c  3bf8                 cmp edi, eax
// 00777f6e  741a                 je 0x777f8a
// 00777f70  8906                 mov dword ptr [esi], eax
// 00777f72  85c0                 test eax, eax
// 00777f74  7408                 je 0x777f7e
// 00777f76  8b08                 mov ecx, dword ptr [eax]
// 00777f78  8b5104               mov edx, dword ptr [ecx + 4]
// 00777f7b  50                   push eax
// 00777f7c  ffd2                 call edx
// 00777f7e  85ff                 test edi, edi
// 00777f80  7408                 je 0x777f8a
// 00777f82  8b07                 mov eax, dword ptr [edi]
// 00777f84  8b4808               mov ecx, dword ptr [eax + 8]
// 00777f87  57                   push edi
// 00777f88  ffd1                 call ecx
// 00777f8a  5f                   pop edi
// 00777f8b  8bc6                 mov eax, esi
// 00777f8d  5e                   pop esi
// 00777f8e  c20400               ret 4
// library xtp-15.2.1/Source\Calendar\XTPCalendarDatabaseDataProvider.cpp (function ??4?$_com_ptr_t@V?$_com_IIID@U_Recordset@XTPADODB@@$1?_GUID_00000556_0000_0010_8000_00aa006d2ea4@@3U__s_GUID@@B@@@@QAEAAV0@ABV0@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarDatabaseDataProvider.cpp
