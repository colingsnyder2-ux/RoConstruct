// from server: 100% by auto
// roc 2012-06 00493700  unit: ToggleBackpackVisibility  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00493700
//
// 00493700  56                   push esi
// 00493701  8bf1                 mov esi, ecx
// 00493703  8b06                 mov eax, dword ptr [esi]
// 00493705  57                   push edi
// 00493706  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0049370a  3bc7                 cmp eax, edi
// 0049370c  741e                 je 0x49372c
// 0049370e  85ff                 test edi, edi
// 00493710  7408                 je 0x49371a
// 00493712  8b07                 mov eax, dword ptr [edi]
// 00493714  8b4804               mov ecx, dword ptr [eax + 4]
// 00493717  57                   push edi
// 00493718  ffd1                 call ecx
// 0049371a  8b06                 mov eax, dword ptr [esi]
// 0049371c  85c0                 test eax, eax
// 0049371e  7408                 je 0x493728
// 00493720  8b10                 mov edx, dword ptr [eax]
// 00493722  50                   push eax
// 00493723  8b4208               mov eax, dword ptr [edx + 8]
// 00493726  ffd0                 call eax
// 00493728  893e                 mov dword ptr [esi], edi
// 0049372a  8bc7                 mov eax, edi
// 0049372c  5f                   pop edi
// 0049372d  5e                   pop esi
// 0049372e  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??4?$CComPtr@UIWebBrowser2@@@ATL@@QAEPAUIWebBrowser2@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
