// from server: 100% by auto
// roc 2008-06 00403af0  unit: ATL::CComClassFactory  size: 77 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00403af0
//
// 00403af0  56                   push esi
// 00403af1  57                   push edi
// 00403af2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00403af6  8b07                 mov eax, dword ptr [edi]
// 00403af8  50                   push eax
// 00403af9  8bf1                 mov esi, ecx
// 00403afb  e8b0f4ffff           call 0x402fb0
// 00403b00  84c0                 test al, al
// 00403b02  7532                 jne 0x403b36
// 00403b04  8b07                 mov eax, dword ptr [edi]
// 00403b06  85f6                 test esi, esi
// 00403b08  7507                 jne 0x403b11
// 00403b0a  5f                   pop edi
// 00403b0b  33c0                 xor eax, eax
// 00403b0d  5e                   pop esi
// 00403b0e  c20400               ret 4
// 00403b11  8b3e                 mov edi, dword ptr [esi]
// 00403b13  c70600000000         mov dword ptr [esi], 0
// 00403b19  85c0                 test eax, eax
// 00403b1b  740d                 je 0x403b2a
// 00403b1d  8b08                 mov ecx, dword ptr [eax]
// 00403b1f  8b11                 mov edx, dword ptr [ecx]
// 00403b21  56                   push esi
// 00403b22  68f0b18000           push 0x80b1f0
// 00403b27  50                   push eax
// 00403b28  ffd2                 call edx
// 00403b2a  85ff                 test edi, edi
// 00403b2c  7408                 je 0x403b36
// 00403b2e  8b07                 mov eax, dword ptr [edi]
// 00403b30  8b4808               mov ecx, dword ptr [eax + 8]
// 00403b33  57                   push edi
// 00403b34  ffd1                 call ecx
// 00403b36  8b06                 mov eax, dword ptr [esi]
// 00403b38  5f                   pop edi
// 00403b39  5e                   pop esi
// 00403b3a  c20400               ret 4
// library atl-9.0/atl.cpp (function ??$?4UITypeInfo2@@@?$CComPtr@UITypeInfo@@@ATL@@QAEPAUITypeInfo@@ABV?$CComPtr@UITypeInfo2@@@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
