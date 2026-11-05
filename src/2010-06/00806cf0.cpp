// from server: 100% by auto
// roc 2010-06 00806cf0  unit: CXTPPropExchangeXMLNode  size: 151 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00806cf0
//
// 00806cf0  56                   push esi
// 00806cf1  57                   push edi
// 00806cf2  8bf9                 mov edi, ecx
// 00806cf4  8b07                 mov eax, dword ptr [edi]
// 00806cf6  85c0                 test eax, eax
// 00806cf8  7408                 je 0x806d02
// 00806cfa  8b08                 mov ecx, dword ptr [eax]
// 00806cfc  8b5108               mov edx, dword ptr [ecx + 8]
// 00806cff  50                   push eax
// 00806d00  ffd2                 call edx
// 00806d02  8b442414             mov eax, dword ptr [esp + 0x14]
// 00806d06  a814                 test al, 0x14
// 00806d08  7453                 je 0x806d5d
// 00806d0a  8b542410             mov edx, dword ptr [esp + 0x10]
// 00806d0e  8d4c2410             lea ecx, [esp + 0x10]
// 00806d12  51                   push ecx
// 00806d13  684007a000           push 0xa00740
// 00806d18  50                   push eax
// 00806d19  8b442418             mov eax, dword ptr [esp + 0x18]
// 00806d1d  52                   push edx
// 00806d1e  50                   push eax
// 00806d1f  ff15dcd09e00         call dword ptr [0x9ed0dc]
// 00806d25  8bf0                 mov esi, eax
// 00806d27  85f6                 test esi, esi
// 00806d29  7c4f                 jl 0x806d7a
// 00806d2b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00806d2f  51                   push ecx
// 00806d30  ff15d0d09e00         call dword ptr [0x9ed0d0]
// 00806d36  8bf0                 mov esi, eax
// 00806d38  85f6                 test esi, esi
// 00806d3a  7c13                 jl 0x806d4f
// 00806d3c  8b442410             mov eax, dword ptr [esp + 0x10]
// 00806d40  8b10                 mov edx, dword ptr [eax]
// 00806d42  57                   push edi
// 00806d43  68ec06a600           push 0xa606ec
// 00806d48  50                   push eax
// 00806d49  8b02                 mov eax, dword ptr [edx]
// 00806d4b  ffd0                 call eax
// 00806d4d  8bf0                 mov esi, eax
// 00806d4f  8b442410             mov eax, dword ptr [esp + 0x10]
// 00806d53  8b08                 mov ecx, dword ptr [eax]
// 00806d55  8b5108               mov edx, dword ptr [ecx + 8]
// 00806d58  50                   push eax
// 00806d59  ffd2                 call edx
// 00806d5b  eb19                 jmp 0x806d76
// 00806d5d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00806d61  57                   push edi
// 00806d62  68ec06a600           push 0xa606ec
// 00806d67  50                   push eax
// 00806d68  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00806d6c  50                   push eax
// 00806d6d  51                   push ecx
// 00806d6e  ff15dcd09e00         call dword ptr [0x9ed0dc]
// 00806d74  8bf0                 mov esi, eax
// 00806d76  85f6                 test esi, esi
// 00806d78  7d06                 jge 0x806d80
// 00806d7a  c70700000000         mov dword ptr [edi], 0
// 00806d80  5f                   pop edi
// 00806d81  8bc6                 mov eax, esi
// 00806d83  5e                   pop esi
// 00806d84  c20c00               ret 0xc
// library xtp-13.2.1/Source\Calendar\XTPCalendarMemoryDataProvider.cpp (function ?CreateInstance@?$_com_ptr_t@V?$_com_IIID@UIXMLDOMDocument@XTPXML@@$1?_GUID_2933bf81_7b36_11d2_b20e_00c04f983e60@@3U__s_GUID@@B@@@@QAEJABU_GUID@@PAUIUnknown@@K@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPCalendarMemoryDataProvider.cpp
