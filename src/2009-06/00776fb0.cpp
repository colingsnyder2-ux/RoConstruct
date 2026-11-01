// from server: 100% by auto
// roc 2009-06 00776fb0  unit: CXTPPropExchangeArchive  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00776fb0
//
// 00776fb0  51                   push ecx
// 00776fb1  8b442408             mov eax, dword ptr [esp + 8]
// 00776fb5  56                   push esi
// 00776fb6  57                   push edi
// 00776fb7  8bf1                 mov esi, ecx
// 00776fb9  85c0                 test eax, eax
// 00776fbb  7437                 je 0x776ff4
// 00776fbd  8b08                 mov ecx, dword ptr [eax]
// 00776fbf  53                   push ebx
// 00776fc0  8d54240c             lea edx, [esp + 0xc]
// 00776fc4  52                   push edx
// 00776fc5  6884bf8f00           push 0x8fbf84
// 00776fca  50                   push eax
// 00776fcb  8b01                 mov eax, dword ptr [ecx]
// 00776fcd  ffd0                 call eax
// 00776fcf  33db                 xor ebx, ebx
// 00776fd1  8bf8                 mov edi, eax
// 00776fd3  8b06                 mov eax, dword ptr [esi]
// 00776fd5  85ff                 test edi, edi
// 00776fd7  0f9cc3               setl bl
// 00776fda  4b                   dec ebx
// 00776fdb  235c240c             and ebx, dword ptr [esp + 0xc]
// 00776fdf  85c0                 test eax, eax
// 00776fe1  7408                 je 0x776feb
// 00776fe3  8b08                 mov ecx, dword ptr [eax]
// 00776fe5  8b5108               mov edx, dword ptr [ecx + 8]
// 00776fe8  50                   push eax
// 00776fe9  ffd2                 call edx
// 00776feb  8b442414             mov eax, dword ptr [esp + 0x14]
// 00776fef  891e                 mov dword ptr [esi], ebx
// 00776ff1  5b                   pop ebx
// 00776ff2  eb1d                 jmp 0x777011
// 00776ff4  8b0e                 mov ecx, dword ptr [esi]
// 00776ff6  85c9                 test ecx, ecx
// 00776ff8  7412                 je 0x77700c
// 00776ffa  c70600000000         mov dword ptr [esi], 0
// 00777000  8b01                 mov eax, dword ptr [ecx]
// 00777002  51                   push ecx
// 00777003  8b4808               mov ecx, dword ptr [eax + 8]
// 00777006  ffd1                 call ecx
// 00777008  8b442410             mov eax, dword ptr [esp + 0x10]
// 0077700c  bf02400080           mov edi, 0x80004002
// 00777011  85c0                 test eax, eax
// 00777013  7408                 je 0x77701d
// 00777015  8b10                 mov edx, dword ptr [eax]
// 00777017  50                   push eax
// 00777018  8b4208               mov eax, dword ptr [edx + 8]
// 0077701b  ffd0                 call eax
// 0077701d  8bc7                 mov eax, edi
// 0077701f  5f                   pop edi
// 00777020  5e                   pop esi
// 00777021  59                   pop ecx
// 00777022  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPPropExchange.cpp (function ??$_QueryInterface@V?$_com_ptr_t@V?$_com_IIID@UIXMLDOMNode@XTPXML@@$1?_GUID_2933bf80_7b36_11d2_b20e_00c04f983e60@@3U__s_GUID@@B@@@@@?$_com_ptr_t@V?$_com_IIID@UIXMLDOMDocument@XTPXML@@$1?_GUID_2933bf81_7b36_11d2_b20e_00c04f983e60@@3U__s_GUID@@B@@@@AAEJV?$_com_ptr_t@V?$_com_IIID@UIXMLDOMNode@XTPXML@@$1?_GUID_2933bf80_7b36_11d2_b20e_00c04f983e60@@3U__s_GUID@@B@@@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPPropExchange.cpp
