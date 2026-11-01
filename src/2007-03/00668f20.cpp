// from server: 100% by auto
// roc 2007-03 00668f20  unit: seg_00660000  size: 151 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00668f20
//
// 00668f20  56                   push esi
// 00668f21  57                   push edi
// 00668f22  8bf9                 mov edi, ecx
// 00668f24  8b07                 mov eax, dword ptr [edi]
// 00668f26  85c0                 test eax, eax
// 00668f28  7408                 je 0x668f32
// 00668f2a  8b08                 mov ecx, dword ptr [eax]
// 00668f2c  8b5108               mov edx, dword ptr [ecx + 8]
// 00668f2f  50                   push eax
// 00668f30  ffd2                 call edx
// 00668f32  8b442414             mov eax, dword ptr [esp + 0x14]
// 00668f36  a814                 test al, 0x14
// 00668f38  7453                 je 0x668f8d
// 00668f3a  8b542410             mov edx, dword ptr [esp + 0x10]
// 00668f3e  8d4c2410             lea ecx, [esp + 0x10]
// 00668f42  51                   push ecx
// 00668f43  68b43e7800           push 0x783eb4
// 00668f48  50                   push eax
// 00668f49  8b442418             mov eax, dword ptr [esp + 0x18]
// 00668f4d  52                   push edx
// 00668f4e  50                   push eax
// 00668f4f  ff1538f17700         call dword ptr [0x77f138]
// 00668f55  8bf0                 mov esi, eax
// 00668f57  85f6                 test esi, esi
// 00668f59  7c4f                 jl 0x668faa
// 00668f5b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00668f5f  51                   push ecx
// 00668f60  ff1518f17700         call dword ptr [0x77f118]
// 00668f66  8bf0                 mov esi, eax
// 00668f68  85f6                 test esi, esi
// 00668f6a  7c13                 jl 0x668f7f
// 00668f6c  8b442410             mov eax, dword ptr [esp + 0x10]
// 00668f70  8b10                 mov edx, dword ptr [eax]
// 00668f72  57                   push edi
// 00668f73  68d8ab7c00           push 0x7cabd8
// 00668f78  50                   push eax
// 00668f79  8b02                 mov eax, dword ptr [edx]
// 00668f7b  ffd0                 call eax
// 00668f7d  8bf0                 mov esi, eax
// 00668f7f  8b442410             mov eax, dword ptr [esp + 0x10]
// 00668f83  8b08                 mov ecx, dword ptr [eax]
// 00668f85  8b5108               mov edx, dword ptr [ecx + 8]
// 00668f88  50                   push eax
// 00668f89  ffd2                 call edx
// 00668f8b  eb19                 jmp 0x668fa6
// 00668f8d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00668f91  57                   push edi
// 00668f92  68d8ab7c00           push 0x7cabd8
// 00668f97  50                   push eax
// 00668f98  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00668f9c  50                   push eax
// 00668f9d  51                   push ecx
// 00668f9e  ff1538f17700         call dword ptr [0x77f138]
// 00668fa4  8bf0                 mov esi, eax
// 00668fa6  85f6                 test esi, esi
// 00668fa8  7d06                 jge 0x668fb0
// 00668faa  c70700000000         mov dword ptr [edi], 0
// 00668fb0  5f                   pop edi
// 00668fb1  8bc6                 mov eax, esi
// 00668fb3  5e                   pop esi
// 00668fb4  c20c00               ret 0xc
// library xtp-15.2.1/Source\Calendar\XTPCalendarMemoryDataProvider.cpp (function ?CreateInstance@?$_com_ptr_t@V?$_com_IIID@UIXMLDOMDocument@XTPXML@@$1?_GUID_2933bf81_7b36_11d2_b20e_00c04f983e60@@3U__s_GUID@@B@@@@QAEJABU_GUID@@PAUIUnknown@@K@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarMemoryDataProvider.cpp
