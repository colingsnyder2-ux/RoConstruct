// from server: 100% by auto
// roc 2009-12 00406ab0  unit: VCApp::?$CComObject  size: 77 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00406ab0
//
// 00406ab0  56                   push esi
// 00406ab1  57                   push edi
// 00406ab2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00406ab6  8b07                 mov eax, dword ptr [edi]
// 00406ab8  50                   push eax
// 00406ab9  8bf1                 mov esi, ecx
// 00406abb  e800feffff           call 0x4068c0
// 00406ac0  84c0                 test al, al
// 00406ac2  7532                 jne 0x406af6
// 00406ac4  8b07                 mov eax, dword ptr [edi]
// 00406ac6  85f6                 test esi, esi
// 00406ac8  7507                 jne 0x406ad1
// 00406aca  5f                   pop edi
// 00406acb  33c0                 xor eax, eax
// 00406acd  5e                   pop esi
// 00406ace  c20400               ret 4
// 00406ad1  8b3e                 mov edi, dword ptr [esi]
// 00406ad3  c70600000000         mov dword ptr [esi], 0
// 00406ad9  85c0                 test eax, eax
// 00406adb  740d                 je 0x406aea
// 00406add  8b08                 mov ecx, dword ptr [eax]
// 00406adf  8b11                 mov edx, dword ptr [ecx]
// 00406ae1  56                   push esi
// 00406ae2  68acfb9900           push 0x99fbac
// 00406ae7  50                   push eax
// 00406ae8  ffd2                 call edx
// 00406aea  85ff                 test edi, edi
// 00406aec  7408                 je 0x406af6
// 00406aee  8b07                 mov eax, dword ptr [edi]
// 00406af0  8b4808               mov ecx, dword ptr [eax + 8]
// 00406af3  57                   push edi
// 00406af4  ffd1                 call ecx
// 00406af6  8b06                 mov eax, dword ptr [esi]
// 00406af8  5f                   pop edi
// 00406af9  5e                   pop esi
// 00406afa  c20400               ret 4
// library atl-9.0/atl.cpp (function ??$?4UITypeInfo2@@@?$CComPtr@UITypeInfo@@@ATL@@QAEPAUITypeInfo@@ABV?$CComPtr@UITypeInfo2@@@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
