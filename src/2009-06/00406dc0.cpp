// from server: 100% by auto
// roc 2009-06 00406dc0  unit: VCApp::?$CComObject  size: 77 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00406dc0
//
// 00406dc0  56                   push esi
// 00406dc1  57                   push edi
// 00406dc2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00406dc6  8b07                 mov eax, dword ptr [edi]
// 00406dc8  50                   push eax
// 00406dc9  8bf1                 mov esi, ecx
// 00406dcb  e8d0fdffff           call 0x406ba0
// 00406dd0  84c0                 test al, al
// 00406dd2  7532                 jne 0x406e06
// 00406dd4  8b07                 mov eax, dword ptr [edi]
// 00406dd6  85f6                 test esi, esi
// 00406dd8  7507                 jne 0x406de1
// 00406dda  5f                   pop edi
// 00406ddb  33c0                 xor eax, eax
// 00406ddd  5e                   pop esi
// 00406dde  c20400               ret 4
// 00406de1  8b3e                 mov edi, dword ptr [esi]
// 00406de3  c70600000000         mov dword ptr [esi], 0
// 00406de9  85c0                 test eax, eax
// 00406deb  740d                 je 0x406dfa
// 00406ded  8b08                 mov ecx, dword ptr [eax]
// 00406def  8b11                 mov edx, dword ptr [ecx]
// 00406df1  56                   push esi
// 00406df2  686cd08a00           push 0x8ad06c
// 00406df7  50                   push eax
// 00406df8  ffd2                 call edx
// 00406dfa  85ff                 test edi, edi
// 00406dfc  7408                 je 0x406e06
// 00406dfe  8b07                 mov eax, dword ptr [edi]
// 00406e00  8b4808               mov ecx, dword ptr [eax + 8]
// 00406e03  57                   push edi
// 00406e04  ffd1                 call ecx
// 00406e06  8b06                 mov eax, dword ptr [esi]
// 00406e08  5f                   pop edi
// 00406e09  5e                   pop esi
// 00406e0a  c20400               ret 4
// library atl-9.0/atl.cpp (function ??$?4UITypeInfo2@@@?$CComPtr@UITypeInfo@@@ATL@@QAEPAUITypeInfo@@ABV?$CComPtr@UITypeInfo2@@@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
