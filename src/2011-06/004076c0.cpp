// from server: 100% by auto
// roc 2011-06 004076c0  unit: VCApp::?$CComObject  size: 77 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004076c0
//
// 004076c0  56                   push esi
// 004076c1  57                   push edi
// 004076c2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004076c6  8b07                 mov eax, dword ptr [edi]
// 004076c8  50                   push eax
// 004076c9  8bf1                 mov esi, ecx
// 004076cb  e8e0fdffff           call 0x4074b0
// 004076d0  84c0                 test al, al
// 004076d2  7532                 jne 0x407706
// 004076d4  8b07                 mov eax, dword ptr [edi]
// 004076d6  85f6                 test esi, esi
// 004076d8  7507                 jne 0x4076e1
// 004076da  5f                   pop edi
// 004076db  33c0                 xor eax, eax
// 004076dd  5e                   pop esi
// 004076de  c20400               ret 4
// 004076e1  8b3e                 mov edi, dword ptr [esi]
// 004076e3  c70600000000         mov dword ptr [esi], 0
// 004076e9  85c0                 test eax, eax
// 004076eb  740d                 je 0x4076fa
// 004076ed  8b08                 mov ecx, dword ptr [eax]
// 004076ef  8b11                 mov edx, dword ptr [ecx]
// 004076f1  56                   push esi
// 004076f2  68f0bca500           push 0xa5bcf0
// 004076f7  50                   push eax
// 004076f8  ffd2                 call edx
// 004076fa  85ff                 test edi, edi
// 004076fc  7408                 je 0x407706
// 004076fe  8b07                 mov eax, dword ptr [edi]
// 00407700  8b4808               mov ecx, dword ptr [eax + 8]
// 00407703  57                   push edi
// 00407704  ffd1                 call ecx
// 00407706  8b06                 mov eax, dword ptr [esi]
// 00407708  5f                   pop edi
// 00407709  5e                   pop esi
// 0040770a  c20400               ret 4
// library atl-9.0/atl.cpp (function ??$?4UITypeInfo2@@@?$CComPtr@UITypeInfo@@@ATL@@QAEPAUITypeInfo@@ABV?$CComPtr@UITypeInfo2@@@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
