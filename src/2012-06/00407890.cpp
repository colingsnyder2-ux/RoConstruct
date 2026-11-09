// from server: 100% by auto
// roc 2012-06 00407890  unit: VCApp::?$CComObject  size: 77 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00407890
//
// 00407890  56                   push esi
// 00407891  57                   push edi
// 00407892  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00407896  8b07                 mov eax, dword ptr [edi]
// 00407898  50                   push eax
// 00407899  8bf1                 mov esi, ecx
// 0040789b  e810feffff           call 0x4076b0
// 004078a0  84c0                 test al, al
// 004078a2  7532                 jne 0x4078d6
// 004078a4  8b07                 mov eax, dword ptr [edi]
// 004078a6  85f6                 test esi, esi
// 004078a8  7507                 jne 0x4078b1
// 004078aa  5f                   pop edi
// 004078ab  33c0                 xor eax, eax
// 004078ad  5e                   pop esi
// 004078ae  c20400               ret 4
// 004078b1  8b3e                 mov edi, dword ptr [esi]
// 004078b3  c70600000000         mov dword ptr [esi], 0
// 004078b9  85c0                 test eax, eax
// 004078bb  740d                 je 0x4078ca
// 004078bd  8b08                 mov ecx, dword ptr [eax]
// 004078bf  8b11                 mov edx, dword ptr [ecx]
// 004078c1  56                   push esi
// 004078c2  68603ab400           push 0xb43a60
// 004078c7  50                   push eax
// 004078c8  ffd2                 call edx
// 004078ca  85ff                 test edi, edi
// 004078cc  7408                 je 0x4078d6
// 004078ce  8b07                 mov eax, dword ptr [edi]
// 004078d0  8b4808               mov ecx, dword ptr [eax + 8]
// 004078d3  57                   push edi
// 004078d4  ffd1                 call ecx
// 004078d6  8b06                 mov eax, dword ptr [esi]
// 004078d8  5f                   pop edi
// 004078d9  5e                   pop esi
// 004078da  c20400               ret 4
// library atl-9.0/atl.cpp (function ??$?4UITypeInfo2@@@?$CComPtr@UITypeInfo@@@ATL@@QAEPAUITypeInfo@@ABV?$CComPtr@UITypeInfo2@@@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
