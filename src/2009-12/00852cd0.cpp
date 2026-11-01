// from server: 100% by auto
// roc 2009-12 00852cd0  unit: CXTPPropExchangeXMLNode  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00852cd0
//
// 00852cd0  8b442404             mov eax, dword ptr [esp + 4]
// 00852cd4  8b00                 mov eax, dword ptr [eax]
// 00852cd6  56                   push esi
// 00852cd7  8bf1                 mov esi, ecx
// 00852cd9  57                   push edi
// 00852cda  8b3e                 mov edi, dword ptr [esi]
// 00852cdc  3bf8                 cmp edi, eax
// 00852cde  741a                 je 0x852cfa
// 00852ce0  8906                 mov dword ptr [esi], eax
// 00852ce2  85c0                 test eax, eax
// 00852ce4  7408                 je 0x852cee
// 00852ce6  8b08                 mov ecx, dword ptr [eax]
// 00852ce8  8b5104               mov edx, dword ptr [ecx + 4]
// 00852ceb  50                   push eax
// 00852cec  ffd2                 call edx
// 00852cee  85ff                 test edi, edi
// 00852cf0  7408                 je 0x852cfa
// 00852cf2  8b07                 mov eax, dword ptr [edi]
// 00852cf4  8b4808               mov ecx, dword ptr [eax + 8]
// 00852cf7  57                   push edi
// 00852cf8  ffd1                 call ecx
// 00852cfa  5f                   pop edi
// 00852cfb  8bc6                 mov eax, esi
// 00852cfd  5e                   pop esi
// 00852cfe  c20400               ret 4
// library xtp-15.2.1/Source\Calendar\XTPCalendarDatabaseDataProvider.cpp (function ??4?$_com_ptr_t@V?$_com_IIID@U_Recordset@XTPADODB@@$1?_GUID_00000556_0000_0010_8000_00aa006d2ea4@@3U__s_GUID@@B@@@@QAEAAV0@ABV0@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarDatabaseDataProvider.cpp
