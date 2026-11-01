// from server: 100% by auto
// roc 2009-06 00777ec0  unit: CXTPPropExchangeXMLNode  size: 151 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00777ec0
//
// 00777ec0  56                   push esi
// 00777ec1  57                   push edi
// 00777ec2  8bf9                 mov edi, ecx
// 00777ec4  8b07                 mov eax, dword ptr [edi]
// 00777ec6  85c0                 test eax, eax
// 00777ec8  7408                 je 0x777ed2
// 00777eca  8b08                 mov ecx, dword ptr [eax]
// 00777ecc  8b5108               mov edx, dword ptr [ecx + 8]
// 00777ecf  50                   push eax
// 00777ed0  ffd2                 call edx
// 00777ed2  8b442414             mov eax, dword ptr [esp + 0x14]
// 00777ed6  a814                 test al, 0x14
// 00777ed8  7453                 je 0x777f2d
// 00777eda  8b542410             mov edx, dword ptr [esp + 0x10]
// 00777ede  8d4c2410             lea ecx, [esp + 0x10]
// 00777ee2  51                   push ecx
// 00777ee3  685cd08a00           push 0x8ad05c
// 00777ee8  50                   push eax
// 00777ee9  8b442418             mov eax, dword ptr [esp + 0x18]
// 00777eed  52                   push edx
// 00777eee  50                   push eax
// 00777eef  ff1500038a00         call dword ptr [0x8a0300]
// 00777ef5  8bf0                 mov esi, eax
// 00777ef7  85f6                 test esi, esi
// 00777ef9  7c4f                 jl 0x777f4a
// 00777efb  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00777eff  51                   push ecx
// 00777f00  ff1518038a00         call dword ptr [0x8a0318]
// 00777f06  8bf0                 mov esi, eax
// 00777f08  85f6                 test esi, esi
// 00777f0a  7c13                 jl 0x777f1f
// 00777f0c  8b442410             mov eax, dword ptr [esp + 0x10]
// 00777f10  8b10                 mov edx, dword ptr [eax]
// 00777f12  57                   push edi
// 00777f13  6884bf8f00           push 0x8fbf84
// 00777f18  50                   push eax
// 00777f19  8b02                 mov eax, dword ptr [edx]
// 00777f1b  ffd0                 call eax
// 00777f1d  8bf0                 mov esi, eax
// 00777f1f  8b442410             mov eax, dword ptr [esp + 0x10]
// 00777f23  8b08                 mov ecx, dword ptr [eax]
// 00777f25  8b5108               mov edx, dword ptr [ecx + 8]
// 00777f28  50                   push eax
// 00777f29  ffd2                 call edx
// 00777f2b  eb19                 jmp 0x777f46
// 00777f2d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00777f31  57                   push edi
// 00777f32  6884bf8f00           push 0x8fbf84
// 00777f37  50                   push eax
// 00777f38  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00777f3c  50                   push eax
// 00777f3d  51                   push ecx
// 00777f3e  ff1500038a00         call dword ptr [0x8a0300]
// 00777f44  8bf0                 mov esi, eax
// 00777f46  85f6                 test esi, esi
// 00777f48  7d06                 jge 0x777f50
// 00777f4a  c70700000000         mov dword ptr [edi], 0
// 00777f50  5f                   pop edi
// 00777f51  8bc6                 mov eax, esi
// 00777f53  5e                   pop esi
// 00777f54  c20c00               ret 0xc
// library xtp-15.2.1/Source\Calendar\XTPCalendarMemoryDataProvider.cpp (function ?CreateInstance@?$_com_ptr_t@V?$_com_IIID@UIXMLDOMDocument@XTPXML@@$1?_GUID_2933bf81_7b36_11d2_b20e_00c04f983e60@@3U__s_GUID@@B@@@@QAEJABU_GUID@@PAUIUnknown@@K@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarMemoryDataProvider.cpp
