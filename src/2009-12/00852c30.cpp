// from server: 100% by auto
// roc 2009-12 00852c30  unit: CXTPPropExchangeXMLNode  size: 151 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00852c30
//
// 00852c30  56                   push esi
// 00852c31  57                   push edi
// 00852c32  8bf9                 mov edi, ecx
// 00852c34  8b07                 mov eax, dword ptr [edi]
// 00852c36  85c0                 test eax, eax
// 00852c38  7408                 je 0x852c42
// 00852c3a  8b08                 mov ecx, dword ptr [eax]
// 00852c3c  8b5108               mov edx, dword ptr [ecx + 8]
// 00852c3f  50                   push eax
// 00852c40  ffd2                 call edx
// 00852c42  8b442414             mov eax, dword ptr [esp + 0x14]
// 00852c46  a814                 test al, 0x14
// 00852c48  7453                 je 0x852c9d
// 00852c4a  8b542410             mov edx, dword ptr [esp + 0x10]
// 00852c4e  8d4c2410             lea ecx, [esp + 0x10]
// 00852c52  51                   push ecx
// 00852c53  689cfb9900           push 0x99fb9c
// 00852c58  50                   push eax
// 00852c59  8b442418             mov eax, dword ptr [esp + 0x18]
// 00852c5d  52                   push edx
// 00852c5e  50                   push eax
// 00852c5f  ff15a4e09800         call dword ptr [0x98e0a4]
// 00852c65  8bf0                 mov esi, eax
// 00852c67  85f6                 test esi, esi
// 00852c69  7c4f                 jl 0x852cba
// 00852c6b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00852c6f  51                   push ecx
// 00852c70  ff15c8e09800         call dword ptr [0x98e0c8]
// 00852c76  8bf0                 mov esi, eax
// 00852c78  85f6                 test esi, esi
// 00852c7a  7c13                 jl 0x852c8f
// 00852c7c  8b442410             mov eax, dword ptr [esp + 0x10]
// 00852c80  8b10                 mov edx, dword ptr [eax]
// 00852c82  57                   push edi
// 00852c83  682cc49f00           push 0x9fc42c
// 00852c88  50                   push eax
// 00852c89  8b02                 mov eax, dword ptr [edx]
// 00852c8b  ffd0                 call eax
// 00852c8d  8bf0                 mov esi, eax
// 00852c8f  8b442410             mov eax, dword ptr [esp + 0x10]
// 00852c93  8b08                 mov ecx, dword ptr [eax]
// 00852c95  8b5108               mov edx, dword ptr [ecx + 8]
// 00852c98  50                   push eax
// 00852c99  ffd2                 call edx
// 00852c9b  eb19                 jmp 0x852cb6
// 00852c9d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00852ca1  57                   push edi
// 00852ca2  682cc49f00           push 0x9fc42c
// 00852ca7  50                   push eax
// 00852ca8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00852cac  50                   push eax
// 00852cad  51                   push ecx
// 00852cae  ff15a4e09800         call dword ptr [0x98e0a4]
// 00852cb4  8bf0                 mov esi, eax
// 00852cb6  85f6                 test esi, esi
// 00852cb8  7d06                 jge 0x852cc0
// 00852cba  c70700000000         mov dword ptr [edi], 0
// 00852cc0  5f                   pop edi
// 00852cc1  8bc6                 mov eax, esi
// 00852cc3  5e                   pop esi
// 00852cc4  c20c00               ret 0xc
// library xtp-15.2.1/Source\Calendar\XTPCalendarMemoryDataProvider.cpp (function ?CreateInstance@?$_com_ptr_t@V?$_com_IIID@UIXMLDOMDocument@XTPXML@@$1?_GUID_2933bf81_7b36_11d2_b20e_00c04f983e60@@3U__s_GUID@@B@@@@QAEJABU_GUID@@PAUIUnknown@@K@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarMemoryDataProvider.cpp
