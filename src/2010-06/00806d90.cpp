// from server: 100% by auto
// roc 2010-06 00806d90  unit: CXTPPropExchangeXMLNode  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00806d90
//
// 00806d90  8b442404             mov eax, dword ptr [esp + 4]
// 00806d94  8b00                 mov eax, dword ptr [eax]
// 00806d96  56                   push esi
// 00806d97  8bf1                 mov esi, ecx
// 00806d99  57                   push edi
// 00806d9a  8b3e                 mov edi, dword ptr [esi]
// 00806d9c  3bf8                 cmp edi, eax
// 00806d9e  741a                 je 0x806dba
// 00806da0  8906                 mov dword ptr [esi], eax
// 00806da2  85c0                 test eax, eax
// 00806da4  7408                 je 0x806dae
// 00806da6  8b08                 mov ecx, dword ptr [eax]
// 00806da8  8b5104               mov edx, dword ptr [ecx + 4]
// 00806dab  50                   push eax
// 00806dac  ffd2                 call edx
// 00806dae  85ff                 test edi, edi
// 00806db0  7408                 je 0x806dba
// 00806db2  8b07                 mov eax, dword ptr [edi]
// 00806db4  8b4808               mov ecx, dword ptr [eax + 8]
// 00806db7  57                   push edi
// 00806db8  ffd1                 call ecx
// 00806dba  5f                   pop edi
// 00806dbb  8bc6                 mov eax, esi
// 00806dbd  5e                   pop esi
// 00806dbe  c20400               ret 4
// library xtp-13.2.1/Source\Calendar\XTPCalendarDatabaseDataProvider.cpp (function ??4?$_com_ptr_t@V?$_com_IIID@U_Recordset@XTPADODB@@$1?_GUID_00000556_0000_0010_8000_00aa006d2ea4@@3U__s_GUID@@B@@@@QAEAAV0@ABV0@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPCalendarDatabaseDataProvider.cpp
