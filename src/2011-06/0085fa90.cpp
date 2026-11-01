// from server: 100% by auto
// roc 2011-06 0085fa90  unit: CXTPPropExchangeArchive  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0085fa90
//
// 0085fa90  56                   push esi
// 0085fa91  8bf1                 mov esi, ecx
// 0085fa93  8b06                 mov eax, dword ptr [esi]
// 0085fa95  8b9090000000         mov edx, dword ptr [eax + 0x90]
// 0085fa9b  ffd2                 call edx
// 0085fa9d  85c0                 test eax, eax
// 0085fa9f  7506                 jne 0x85faa7
// 0085faa1  33c0                 xor eax, eax
// 0085faa3  5e                   pop esi
// 0085faa4  c20c00               ret 0xc
// 0085faa7  837e2800             cmp dword ptr [esi + 0x28], 0
// 0085faab  7518                 jne 0x85fac5
// 0085faad  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0085fab1  8b08                 mov ecx, dword ptr [eax]
// 0085fab3  51                   push ecx
// 0085fab4  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 0085fab7  e8c8ce1600           call 0x9cc984
// 0085fabc  b801000000           mov eax, 1
// 0085fac1  5e                   pop esi
// 0085fac2  c20c00               ret 0xc
// 0085fac5  8b442410             mov eax, dword ptr [esp + 0x10]
// 0085fac9  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 0085facc  6a00                 push 0
// 0085face  8d562c               lea edx, [esi + 0x2c]
// 0085fad1  52                   push edx
// 0085fad2  50                   push eax
// 0085fad3  e8a6ce1600           call 0x9cc97e
// 0085fad8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0085fadc  8901                 mov dword ptr [ecx], eax
// 0085fade  85c0                 test eax, eax
// 0085fae0  74bf                 je 0x85faa1
// 0085fae2  b801000000           mov eax, 1
// 0085fae7  5e                   pop esi
// 0085fae8  c20c00               ret 0xc
// library xtp-15.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?ExchangeRuntimeClass@CXTPPropExchangeArchive@@UAEHPBDAAPAUCRuntimeClass@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
