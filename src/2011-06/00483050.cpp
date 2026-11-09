// from server: 100% by auto
// roc 2011-06 00483050  unit: ToggleBackpackVisibility  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00483050
//
// 00483050  56                   push esi
// 00483051  8bf1                 mov esi, ecx
// 00483053  8b06                 mov eax, dword ptr [esi]
// 00483055  57                   push edi
// 00483056  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0048305a  3bc7                 cmp eax, edi
// 0048305c  741e                 je 0x48307c
// 0048305e  85ff                 test edi, edi
// 00483060  7408                 je 0x48306a
// 00483062  8b07                 mov eax, dword ptr [edi]
// 00483064  8b4804               mov ecx, dword ptr [eax + 4]
// 00483067  57                   push edi
// 00483068  ffd1                 call ecx
// 0048306a  8b06                 mov eax, dword ptr [esi]
// 0048306c  85c0                 test eax, eax
// 0048306e  7408                 je 0x483078
// 00483070  8b10                 mov edx, dword ptr [eax]
// 00483072  50                   push eax
// 00483073  8b4208               mov eax, dword ptr [edx + 8]
// 00483076  ffd0                 call eax
// 00483078  893e                 mov dword ptr [esi], edi
// 0048307a  8bc7                 mov eax, edi
// 0048307c  5f                   pop edi
// 0048307d  5e                   pop esi
// 0048307e  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??4?$CComPtr@UIWebBrowser2@@@ATL@@QAEPAUIWebBrowser2@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
