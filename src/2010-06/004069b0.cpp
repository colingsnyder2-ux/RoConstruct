// from server: 100% by auto
// roc 2010-06 004069b0  unit: VCApp::?$CComObject  size: 77 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004069b0
//
// 004069b0  56                   push esi
// 004069b1  57                   push edi
// 004069b2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004069b6  8b07                 mov eax, dword ptr [edi]
// 004069b8  50                   push eax
// 004069b9  8bf1                 mov esi, ecx
// 004069bb  e800feffff           call 0x4067c0
// 004069c0  84c0                 test al, al
// 004069c2  7532                 jne 0x4069f6
// 004069c4  8b07                 mov eax, dword ptr [edi]
// 004069c6  85f6                 test esi, esi
// 004069c8  7507                 jne 0x4069d1
// 004069ca  5f                   pop edi
// 004069cb  33c0                 xor eax, eax
// 004069cd  5e                   pop esi
// 004069ce  c20400               ret 4
// 004069d1  8b3e                 mov edi, dword ptr [esi]
// 004069d3  c70600000000         mov dword ptr [esi], 0
// 004069d9  85c0                 test eax, eax
// 004069db  740d                 je 0x4069ea
// 004069dd  8b08                 mov ecx, dword ptr [eax]
// 004069df  8b11                 mov edx, dword ptr [ecx]
// 004069e1  56                   push esi
// 004069e2  685007a000           push 0xa00750
// 004069e7  50                   push eax
// 004069e8  ffd2                 call edx
// 004069ea  85ff                 test edi, edi
// 004069ec  7408                 je 0x4069f6
// 004069ee  8b07                 mov eax, dword ptr [edi]
// 004069f0  8b4808               mov ecx, dword ptr [eax + 8]
// 004069f3  57                   push edi
// 004069f4  ffd1                 call ecx
// 004069f6  8b06                 mov eax, dword ptr [esi]
// 004069f8  5f                   pop edi
// 004069f9  5e                   pop esi
// 004069fa  c20400               ret 4
// library atl-9.0/atl.cpp (function ??$?4UITypeInfo2@@@?$CComPtr@UITypeInfo@@@ATL@@QAEPAUITypeInfo@@ABV?$CComPtr@UITypeInfo2@@@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
